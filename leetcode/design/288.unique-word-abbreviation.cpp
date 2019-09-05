class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string>& dictionary)
    {
        for (auto a : dictionary) {
            string k = a[0] + to_string(a.size() - 2) + a.back();
            // "" means it's not unique
            if (m.count(k) && m[k] != a)
                m[k] = "";
            else
                m[k].insert(a);
        }
    }

    bool isUnique(string word)
    {
        string k = word[0] + to_string(word.size() - 2) + word.back();
        return !m[k].count(word) || m[k] == word;
    }

private:
    unordered_map<string, set<string>> m;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */
