class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs)
    {
        string res = "";
        for (string str : strs) {
            res += str + '\0';
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s)
    {
        vector<string> res;
        stringstream ss(s);
        string t;
        while (getline(ss, t, '\0')) {
            res.push_back(t);
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
