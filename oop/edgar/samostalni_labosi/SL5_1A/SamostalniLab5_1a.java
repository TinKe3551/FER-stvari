package edgar.samostalni.labosi.SL5_prviA;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.function.Consumer;


enum Result { 
	RESULT_UNDEFINED, 
	RESULT_WHITE_WIN, 
	RESULT_BLACK_WIN, 
	RESULT_DRAW; 
	};

	

public class SamostalniLab5_1a {
	public static void main(String[] args) {
	
		List<Match> matches = new ArrayList<Match>();
		Map<String, Player> mplayers = new HashMap<String, Player>();
		
		mplayers.put("Caruana", new Player("Caruana", 2820));
		mplayers.put("Carlsen", new Player("Carlsen", 2847));
		mplayers.put("Radjabov", new Player("Radjabov", 2765));

		matches.add(new Match("Carlsen", "Radjabov", Result.RESULT_WHITE_WIN));
		matches.add(new Match("Caruana", "Carlsen", Result.RESULT_BLACK_WIN));
		matches.add(new Match("Caruana", "Radjabov", Result.RESULT_DRAW));
		
		
		
		matches.forEach(
				//rjesenje (u prostoru za upisivanje rjesenja se ne mogu koristiti import naredbe)
				new java.util.function.Consumer<Match>() {
					public void accept(Match match) {
						Result result = match.getResult();
						String white = match.getWhitePlayer();
						String black = match.getBlackPlayer();
						
						Player white_pl = mplayers.get(white);
						Player black_pl = mplayers.get(black);
						
						if (result == Result.RESULT_WHITE_WIN) {
							white_pl.setPoints(white_pl.getPoints() + 1.0);
							mplayers.replace(white, white_pl);
						}
						
						else if (result == Result.RESULT_BLACK_WIN) {
							black_pl.setPoints(black_pl.getPoints() + 1.0) ;
							mplayers.replace(black, black_pl);
						}
						
						else if (result == Result.RESULT_DRAW) {
							
							white_pl.setPoints(white_pl.getPoints() + 0.5);
							mplayers.replace(white, white_pl);
							
							black_pl.setPoints(black_pl.getPoints() + 0.5) ;
							mplayers.replace(black, black_pl);
						
						}
					}
				}
			);
		
		
		
		/*
		// ovako bi to inace izgledalo
		matches.forEach(new Consumer<Match>() {
			public void accept(Match match) {
				Result result = match.getResult();
				String white = match.getWhitePlayer();
				String black = match.getBlackPlayer();
				
				Player white_pl = mplayers.get(white);
				Player black_pl = mplayers.get(black);
				
				if (result == Result.RESULT_WHITE_WIN) {
					white_pl.setPoints(white_pl.getPoints() + 1.0);
					mplayers.replace(white, white_pl);
				}
				
				else if (result == Result.RESULT_BLACK_WIN) {
					black_pl.setPoints(black_pl.getPoints() + 1.0) ;
					mplayers.replace(black, black_pl);
				}
				
				else if (result == Result.RESULT_DRAW) {
					
					white_pl.setPoints(white_pl.getPoints() + 0.5);
					mplayers.replace(white, white_pl);
					
					black_pl.setPoints(black_pl.getPoints() + 0.5) ;
					mplayers.replace(black, black_pl);
				}
				
			}
		});*/
		
	}
}


