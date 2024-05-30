package edgar.samostalni.labosi.SL5_prviA;

class Player {
    private String name;
    private int rating;
    private double points;
    private int standing;

    

    public Player(String name, int rating) {
        this.name = name;
        this.rating = rating;
        this.points = 0.0;
        this.standing = 0;
    }
    
    //getteri i setteri
	public String getName() {
		return name;
	}

	public int getRating() {
		return rating;
	}

	public double getPoints() {
		return points;
	}

	public int getStanding() {
		return standing;
	}

	public void setName(String name) {
		this.name = name;
	}

	public void setRating(int rating) {
		this.rating = rating;
	}

	public void setPoints(double points) {
		this.points = points;
	}

	public void setStanding(int standing) {
		this.standing = standing;
	}
}
