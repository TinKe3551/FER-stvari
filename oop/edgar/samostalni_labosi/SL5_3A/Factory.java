package edgar.samostalni.labosi.SL5_treciA;

class Factory {
	
	public static MyGame createGame(String name, int rating) {
		return new MyGame(name, rating);
	}
	
}
