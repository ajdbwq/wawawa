#include <iostream>
#include <vector>
#include <string>
#include <cassert>

class Executor {
private:
    int x;
    int y;
    char heading;

    void turnLeft() {
        switch (heading) {
            case 'N': heading = 'W'; break;
            case 'W': heading = 'S'; break;
            case 'S': heading = 'E'; break;
            case 'E': heading = 'N'; break;
        }
    }

    void turnRight() {
        switch (heading) {
            case 'N': heading = 'E'; break;
            case 'E': heading = 'S'; break;
            case 'S': heading = 'W'; break;
            case 'W': heading = 'N'; break;
        }
    }

    void move() {
        switch (heading) {
            case 'N': y++; break;
            case 'S': y--; break;
            case 'E': x++; break;
            case 'W': x--; break;
        }
    }

public:

    Executor() : x(0), y(0), heading('N') {}

    void initialize(int startX, int startY, char startHeading) {
        x = startX;
        y = startY;
        heading = startHeading;
    }

    void executeCommands(const std::string& commands) {
        for (char command : commands) {
            switch (command) {
                case 'M': move(); break;
                case 'L': turnLeft(); break;
                case 'R': turnRight(); break;
                default: break;
            }
        }
    }

    void getStatus(int& currentX, int& currentY, char& currentHeading) const {
        currentX = x;
        currentY = y;
        currentHeading = heading;
    }
};

void testExecutor() {
    Executor executor;

    int x, y;
    char heading;
    executor.getStatus(x, y, heading);
    assert(x == 0 && y == 0 && heading == 'N');

    executor.initialize(5, 5, 'E');
    executor.getStatus(x, y, heading);
    assert(x == 5 && y == 5 && heading == 'E');

    executor.executeCommands("M");
    executor.getStatus(x, y, heading);
    assert(x == 6 && y == 5 && heading == 'E');

    executor.executeCommands("R");
    executor.getStatus(x, y, heading);
    assert(x == 6 && y == 5 && heading == 'S');

    executor.executeCommands("M");
    executor.getStatus(x, y, heading);
    assert(x == 6 && y == 4 && heading == 'S');

    executor.executeCommands("L");
    executor.getStatus(x, y, heading);
    assert(x == 6 && y == 4 && heading == 'E');

    executor.executeCommands("MMMLMR");
    executor.getStatus(x, y, heading);
    assert(x == 9 && y == 3 && heading == 'S');

    std::cout << "All tests passed successfully!\n";
}

int main() {
    testExecutor();
    return 0;
}
