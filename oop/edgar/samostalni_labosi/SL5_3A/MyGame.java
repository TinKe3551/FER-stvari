package edgar.samostalni.labosi.SL5_treciA;

class MyGame extends Game implements Comparable<Game> {
	
	public MyGame(String name, int rating) {
		super(name);
		this.setRating(rating);
	}

	@Override
	public int compareTo(Game o) {
		return this.getName().compareTo(o.getName());
	}
	
}
