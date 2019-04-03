import java.awt.event.*;

public class CalculatorController {
    private CalculatorView view;
    private CalculatorModel model;

    public CalculatorController(CalculatorView view, CalculatorModel model) {
        this.view = view;
        this.model = model;
        this.view.addSumListener(new CalculatorListener());

    }

    class CalculatorListener implements ActionListener{
        public void actionPerformed(ActionEvent event){
            int x,y =0;
            try{
                x = view.getSumX();
                y = view.getSumY();
                model.sum(x,y);
                view.setSum(model.getSum());
            }
            catch (NumberFormatException e){
                view.displayErr("enter two numbers!");
            }
        }
    }
}
