package p2;

public class Circulo extends Elipse {
	
	@Override
	public void imprimir() {
		System.out.println("Area Circulo = "+getArea()+ "Perimetro Circulo ="+ getPerimetro());
	}
	public Circulo(float a, float b) {
		super(a, b);
	}

}
