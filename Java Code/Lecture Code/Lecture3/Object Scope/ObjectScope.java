class Position {
  int x;
  int y;

  Position(int x, int y) {
    this.x = x;
    this.y = y;
  }

  void move(int dx, int dy) {
    x += dx;
    y += dy;
  }
}

class PositionWorld {

  public static void main (String[] args) {
    Position[] positions = new Position[3];
    int i = 1;
    for (int index = 0; index<positions.length; index++) {
      positions[index] = new Position(1,i++);
    }
    /* for (Position p : positions)
          p = new Position(1,i++)
          does not work because there are currently no position objects
          in positions array/heap allocation so we cannot
          say for each object in positions array */
    positions[2].move(1,1);
    positions[2].move(-1,-2);
    positions[2] = positions[1];
    positions[1].move(0,-1);
  }/*Object methods and attributes are dereferenced meaning they are changed and
     will remain changed. eg Dereferencing(*) in C*/
}
