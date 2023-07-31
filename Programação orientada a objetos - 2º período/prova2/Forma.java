package p2;

public abstract class Forma {
	private float area;
	private float perimetro;
	
	public float getArea() {
		return area;
	}
	
	public void setArea(float area) {
		this.area = area;
	}
	
	public float getPerimetro() {
		return perimetro;
	}
	
	public void setPerimetro(float perimetro) {
		this.perimetro = perimetro;
	}
	public abstract void calcArea();
	public abstract void calcPerimetro();
	public abstract void imprimir();
}
