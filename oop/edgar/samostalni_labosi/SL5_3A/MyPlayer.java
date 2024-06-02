package edgar.samostalni.labosi.SL5_treciA;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.Set;
import java.util.TreeMap;


class MyPlayer extends Player implements Iterable<Game> {
	
	private Map<Game, ArrayList<Integer>> scores = new TreeMap<Game, ArrayList<Integer>>();
	
	public MyPlayer(String name) {
		super(name);
	}
	
	
	public void addGameScore(Game game, int score) {
		ArrayList<Integer> scores_of_game = scores.getOrDefault(game, new ArrayList<Integer>());
		scores_of_game.add(score);
		scores.put(game, scores_of_game);
	}
	
	public Iterable<Integer> getScores(Game game) {
		return scores.get(game);
	}


	@Override
	public Iterator<Game> iterator() {
		return new MyPlayerIterator(scores.keySet());
	}
	
	
	private static class MyPlayerIterator implements Iterator<Game> {
		
		private Game[] games;
		private int size;
		private int i;
		
		public MyPlayerIterator(Set<Game> games) {
			
			this.games = new Game[games.size()];
			
			this.games = games.toArray(this.games);
			this.size = games.size();
			this.i = 0;
			
		}
		
		public Game next() {
			if(this.hasNext()) return this.games[this.i++];
			else throw new NoSuchElementException();
		}
		
		public boolean hasNext() {
			return (this.i < this.size);
		}
		
	}
}
