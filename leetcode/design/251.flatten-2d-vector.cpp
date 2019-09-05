class Vector2D {
public:
    Vector2D(vector<vector<int>>& v)
        : x(v.begin())
        , end(v.end())
    {
    }

    int next()
    {
        hasNext();
        return (*x)[y++];
    }

    bool hasNext()
    {
        while (x != end && y == (*x).size()) {
            ++x;
            y = 0;
        }
        return x != end;
    }

private:
    vector<vector<int>>::iterator x, end;
    int y = 0;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
