/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    unordered_map<int, unordered_map<int,int>> mp;
    int x = 0;
    int y = 0;
    int dirs[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    int dir = 0;
    void cleanRoom(Robot& robot) {
        if(mp[x][y]) return;
        mp[x][y] = 1;
        robot.clean();
        for(int i = 0; i < 4; i++){
            if(robot.move()){
                x += dirs[dir][0];
                y += dirs[dir][1];
                cleanRoom(robot);
                robot.turnLeft();
                robot.turnLeft();
                robot.move();
                robot.turnLeft();
                robot.turnLeft();
                x -= dirs[dir][0];
                y -= dirs[dir][1];
            }
            robot.turnLeft();
            dir = (dir + 1) % 4;
        }
    }
};