class Items<T> extends Artikl {
    private double quantity;

    public Items(T tag, double pricing, Type type, double quantity) {
        super(tag, pricing, type);

        this.quantity = 0;



        if (quantity < 0) {
            throw new IllegalArgumentException("Negative values forbidden");
        }

        if (type == Type.ITEM && (quantity % 1) != 0) {
            throw new IllegalArgumentException("For pricing per item, the quantity cannot have decimals");
        }
        this.quantity = quantity;

    }

    public Items(T tag, double pricing, Type type) {
        this(tag, pricing, type, 0);

    }


    public void setQuantity(double quantity) {

        this.quantity = 0;

        if (quantity < 0) {
            throw new IllegalArgumentException("Negative values forbidden");
        }

        if (this.getType() == Type.ITEM && (quantity % 1) != 0) {
            throw new IllegalArgumentException("For pricing per item, the quantity cannot have decimals");
        }

        this.quantity = quantity;
    }

    public double getPrice() {
        double d = 1;
        if (getType() == Type.KG) {d = 1000;}

        return this.quantity * this.getPricing() / d;
    }

}
