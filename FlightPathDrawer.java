import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;
import java.util.List;

class FlightPath {
    List<Point> coordinates;
    Color color;

    public FlightPath(List<Point> coordinates, Color color) {
        this.coordinates = coordinates;
        this.color = color;
    }
}

public class FlightPathDrawer extends JPanel {

    private final List<FlightPath> flights;

    public FlightPathDrawer(List<FlightPath> flights) {
        this.flights = flights;
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2d = (Graphics2D) g;

        for (FlightPath flight : flights) {
            g2d.setColor(flight.color);
            for (int i = 0; i < flight.coordinates.size() - 1; i++) {
                Point p1 = flight.coordinates.get(i);
                Point p2 = flight.coordinates.get(i + 1);
                g2d.drawLine(p1.x, p1.y, p2.x, p2.y);
                g2d.fillOval(p1.x - 2, p1.y - 2, 4, 4);
                g2d.fillOval(p2.x - 2, p2.y - 2, 4, 4);
            }
        }
    }

    public static void main(String[] args) {
        List<FlightPath> flights = new ArrayList<>();
        flights.add(new FlightPath(List.of(new Point(10, 10), new Point(20, 20), new Point(30, 30)), Color.RED));
        flights.add(new FlightPath(List.of(new Point(10, 10), new Point(20, 40), new Point(30, 20)), Color.BLUE));
        flights.add(new FlightPath(List.of(new Point(10, 10), new Point(40, 20), new Point(30, 40)), Color.GREEN));

        JFrame frame = new JFrame("Flight Paths");
        FlightPathDrawer drawer = new FlightPathDrawer(flights);
        frame.add(drawer);
        frame.setSize(400, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
