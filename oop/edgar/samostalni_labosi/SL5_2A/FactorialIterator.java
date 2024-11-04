package edgar.samostalni.labosi.SL5_drugiA;

import java.util.Iterator;

class FactorialIterator implements Iterator<Integer> {
	
	private Integer max_factor;
	private Integer factor = 0;
	private Integer x = 1;
	
	
	public FactorialIterator(Integer max_factor) {
		
		if (max_factor < 0) throw new IllegalArgumentException();
		
		this.max_factor = max_factor;
	}
	
	
	public Integer next() {
		
		if(hasNext()) {
			if (factor == 0) {
				factor = 1;
				return 1;
			}
			
			x *= factor;
			factor++;
			
			return x;
		}
		
		else throw new java.util.NoSuchElementException();
	}
	
	
	public boolean hasNext() {
		return factor < max_factor;
	}
}
