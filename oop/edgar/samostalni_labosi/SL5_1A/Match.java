package edgar.samostalni.labosi.SL5_prviA;

class Match {
    private String whitePlayer;
    private String blackPlayer;
    private Result result;

    public Match(String whitePlayer, String blackPlayer, Result result) {
        this.whitePlayer = whitePlayer;
        this.blackPlayer = blackPlayer;
        this.result = result;
    }
    
    //getteri i setteri
	public String getWhitePlayer() {
		return whitePlayer;
	}

	public String getBlackPlayer() {
		return blackPlayer;
	}

	public Result getResult() {
		return result;
	}

	public void setWhitePlayer(String whitePlayer) {
		this.whitePlayer = whitePlayer;
	}

	public void setBlackPlayer(String blackPlayer) {
		this.blackPlayer = blackPlayer;
	}

	public void setResult(Result result) {
		this.result = result;
	}
    
    
}
