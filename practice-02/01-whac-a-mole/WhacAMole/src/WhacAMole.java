import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.Timer;

public class WhacAMole {
	int boardWidth = 600;
	int boardHeight = 650;

	JFrame frame = new JFrame("Whac A Mole (Mario Edition)");
	JLabel textLabel = new JLabel();
	JPanel textPanel = new JPanel();
	JPanel boardPanel = new JPanel();

	JButton[] board = new JButton[9];
	ImageIcon collectIcon;
	ImageIcon avoidIcon;

	JButton currentCollectTile;
	JButton currentAvoidTile;
	Random random = new Random();
	Timer setCollectTimer;
	Timer setAvoidTimer;
	int score = 0;

	WhacAMole() {
		frame.setSize(boardWidth, boardHeight);
		frame.setLocationRelativeTo(null);
		frame.setResizable(false);
		frame.setAlwaysOnTop(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setLayout(new BorderLayout());

		textLabel.setFont(new Font("JetBrains Mono", Font.PLAIN, 50));
		textLabel.setHorizontalAlignment(JLabel.CENTER);
		textLabel.setText("Score: 0");
		textLabel.setOpaque(true);

		textPanel.setLayout(new BorderLayout());
		textPanel.add(textLabel);
		frame.add(textPanel, BorderLayout.NORTH);
		
		boardPanel.setLayout(new GridLayout(3, 3));
		boardPanel.setBackground(Color.black);
		frame.add(boardPanel);

		Image avoidImage = new ImageIcon(getClass().getResource("./avoid.png")).getImage();
		avoidIcon = new ImageIcon(avoidImage.getScaledInstance(120, 120, java.awt.Image.SCALE_SMOOTH));
		
		Image collectImage = new ImageIcon(getClass().getResource("./collect.png")).getImage();
		collectIcon = new ImageIcon(collectImage.getScaledInstance(130,130, java.awt.Image.SCALE_SMOOTH));

		for (int i = 0; i < 9; i++) {
			JButton tile = new JButton();
			board[i] = tile;
			boardPanel.add(tile);
			tile.setFocusable(false);
			tile.setIcon(null);
			tile.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					JButton tile = (JButton) e.getSource();
					if (tile == currentCollectTile) {
						score++;
						textLabel.setText("Score: " + Integer.toString(score));
						textLabel.setForeground(Color.black);
					} else if (tile == currentAvoidTile) {
						setCollectTimer.stop();
						setAvoidTimer.stop();
						for (int i = 0; i < 9; i++) {
							board[i].setEnabled(false);
						}
						textLabel.setText("Game Over");
						textLabel.setForeground(Color.red);
					}
				}
			});
		}

		setCollectTimer = new Timer(1000, new ActionListener() {
			public void actionPerformed(ActionEvent e){
				if (currentCollectTile != null) {
					currentCollectTile.setIcon(null);
					currentCollectTile = null;
				}

				int num = random.nextInt(9); // 0-8
				JButton tile = board[num];
				if (currentAvoidTile == tile)
					return;

				currentCollectTile = tile;
				currentCollectTile.setIcon(collectIcon);
			}
		});

		setAvoidTimer = new Timer(1500, new ActionListener() {
			public void actionPerformed(ActionEvent e){
				if (currentAvoidTile != null) {
					currentAvoidTile.setIcon(null);
					currentAvoidTile = null;
				}

				int num = random.nextInt(9); // 0-8
				JButton tile = board[num];
				if (currentCollectTile == tile)
					return;

				currentAvoidTile = tile;
				currentAvoidTile.setIcon(avoidIcon);
			}
		});

		setAvoidTimer.start();
		setCollectTimer.start();
	
		frame.setVisible(true);
	}
}
