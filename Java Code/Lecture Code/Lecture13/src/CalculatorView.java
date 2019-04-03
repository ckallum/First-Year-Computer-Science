import java.awt.event.ActionListener;
import javax.swing.*;

public class CalculatorView extends JFrame{
    private JTextField sumX;
    private JTextField sumY;
    private JLabel sumLabel;
    private JButton sumButton;
    private JTextField sumField;

    public CalculatorView() {
        sumX = new JTextField(10);
        sumY = new JTextField(10);
        sumLabel = new JLabel("+");
        sumButton = new JButton("Sum");
        sumField = new JTextField(10);
        JPanel sumPanel = new JPanel();
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setSize(600,200);

        sumPanel.add(sumX);
        sumPanel.add(sumLabel);
        sumPanel.add(sumY);
        sumPanel.add(sumButton);
        sumPanel.add(sumField);
        this.add(sumPanel);
    }

    public int getSumX() {
        return Integer.parseInt(sumX.getText());
    }

    public int getSumY() {
        return Integer.parseInt(sumY.getText());
    }

    public void setSum(int sum){
        sumField.setText(Integer.toString(sum));
    }
    public void addSumListener(ActionListener listenButton){
        sumButton.addActionListener(listenButton);
    }

    public void displayErr(String err){
        JOptionPane.showMessageDialog(this, err);
    }
}
