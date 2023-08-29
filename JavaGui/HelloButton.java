import javax.swing.JFrame;
import javax.swing.JButton;

public class HelloButton extends JFrame {
	public HelloButton () {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		int len = 100, height = 100, x = 500, y = 500;

		//Hello World Button
		JButton hello = new JButton("Hello World!");
		 hello.setBounds(x, y, len, height); // define parameters x, y, w, h
		 hello.addActionListener( event -> System.out.println(event.getActionCommand()) );

		//Hiding Button
		JButton peekaboo = new JButton("Catch me if you can.");
		 peekaboo.setBounds(20,100,100,100); // define parameters l,w,x,y
		 peekaboo.addActionListener( event ->  peekaboo.setVisible(false) );

		add(hello);
		add(peekaboo);
		//add(incLen);
		//add(decLen);
		//add(incHeight);
		//add(decHeight);


		setSize(600,480);
		setLayout(null);
		setVisible(true);
	}

	
	public static void main(String args[]) {
		new HelloButton();
	}
}
