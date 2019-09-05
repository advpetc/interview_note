class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1],
       the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food)
    {
        this->width = width;
        this->height = height;
        this->food = food;
        score = 0;
        snake.push_back({ 0, 0 });
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction)
    {
        auto head = snake.front(), tail = snake.back();
        snake.pop_back();
        if (direction == "U")
            --head[0];
        if (direction == "L")
            --head[1];
        if (direction == "R")
            ++head[1];
        if (direction == "D")
            ++head[0];
        // count: check the number of appearance of head in snake vector
        if (count(snake.begin(), snake.end(), head) || head[0] < 0
            || head[0] >= height || head[1] < 0 || head[1] >= width)
            return -1;
        snake.insert(snake.begin(), head);
        if (!food.empty() && head == food.front()) {
            food.erase(food.begin());
            snake.push_back(tail);
            ++score;
        }
        return score;
    }

private:
    int width, height, score;
    vector<vector<int>> food, snake;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
