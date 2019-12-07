import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.util.*;

class Asset implements Comparable<Asset> {
    String Name;
    String AssetType; // bond or stock
    int shares;

    public Asset(String name, String assetType, String shares) {
        this.Name = name;
        this.AssetType = assetType;
        this.shares = Integer.parseInt(shares);
    }

    @Override
    public int compareTo(Asset other) {
        return this.Name.compareTo(other.Name);
    }

    @Override
    public String toString() {
        return Name + "," + AssetType + "," + shares;
    }
}

public class Main {

    private static List<Asset> portfolio, benchmark;
    private static Map<String, Map<String, Asset>> data;
    private static List<String> buy, sell;
    /**
     * Iterate through each line of input.
     */
    public static void main(String[] args) throws IOException {
        InputStreamReader reader = new InputStreamReader(System.in, StandardCharsets.UTF_8);
        BufferedReader in = new BufferedReader(reader);
        String line;
        while ((line = in.readLine()) != null) {
            Main.matchBenchmark(line);
        }
    }

    public static void matchBenchmark(String input) {
        // Access your code here. Feel free to create other classes as required
        Main.init(input);
        Main.calculate();
        System.out.println("i is: " + sell.size());
        System.out.println("j is: " + buy.size());
        for (int i = 0; i < sell.size(); i++) {
            System.out.println(sell.get(i));
        }
        for (int j = 0; j < buy.size(); j++) {
            System.out.println(buy.get(j));
        }
    }

    private static void init(String rawInput) {
        // error checking
        if (!rawInput.contains(":"))
            return;
        String[] pb = rawInput.split(":");
        String[] po = pb[0].split("\\|");
        String[] be = pb[1].split("\\|");
        portfolio = new ArrayList<>();
        benchmark = new ArrayList<>();
        data = new HashMap<>();
        for (String p: po) {
            // error checking
            if (!p.contains(","))
                return;
            String[] parts = p.split(",");
            Asset asset = new Asset(parts[0], parts[1], parts[2]);
            portfolio.add(asset);
        }

        for (String b: be) {
            // error checking
            if (!b.contains(","))
                return;
            String[] parts = b.split(",");
            Asset asset = new Asset(parts[0], parts[1], parts[2]);
            benchmark.add(asset);
        }
        buy = new ArrayList<>();
        sell = new ArrayList<>();
    }

    private static void calculate() {
        List<Asset> portBond = new ArrayList<>();
        List<Asset> benchBond = new ArrayList<>();
        List<Asset> portStock = new ArrayList<>();
        List<Asset> benchStock = new ArrayList<>();
        for (Asset asset : benchmark) {
            if (asset.AssetType.equals("BOND"))
                benchBond.add(asset);
            else if (asset.AssetType.equals("STOCK"))
                benchStock.add(asset);
        }

        for (Asset asset : portfolio) {
            if (asset.AssetType.equals("BOND"))
                portBond.add(asset);
            else if (asset.AssetType.equals("STOCK"))
                portStock.add(asset);
        }

        System.out.println("port bond: " + portBond.size());
        System.out.println("bench bond: " + benchBond.size());
        System.out.println("port stock: " + portStock.size());
        System.out.println("bench stock: " + benchStock.size());
        Collections.sort(portBond);
        Collections.sort(benchBond);
        Collections.sort(portStock);
        Collections.sort(benchStock);

        compareAssest(portBond, benchBond);
        compareAssest(portStock, benchStock);
    }

    private static void compareAssest(List<Asset> p, List<Asset> b) {
        int i = 0, j = 0;
        while (i < p.size() || j < b.size()) {
            if (i >= p.size()) {
                for (; j < b.size(); ++j)
                    buy.add("BUY" + b.get(j).toString());
                return;
            } else if (j >= b.size()) {
                for (; i < p.size(); ++i)
                    sell.add("SELL" + p.get(i).toString());
            }
            Asset port = p.get(i), bench = b.get(j);
            if (port.Name.equals(bench.Name)) {
                if (port.shares < bench.shares) {
                    bench.shares -= port.shares;
                    buy.add("BUY" + bench.toString());
                } else if (port.shares > bench.shares) {
                    port.shares -= bench.shares;
                    sell.add("SELL" + port.toString());
                }
                i++;
                j++;
            } else if (port.Name.compareTo(bench.Name) < 0) {
                sell.add("SELL" + port.toString());
                i++;
            } else if (port.Name.compareTo(bench.Name) > 0) {
                buy.add("BUY" + bench.toString());
                j++;
            }
        }
    }
}
