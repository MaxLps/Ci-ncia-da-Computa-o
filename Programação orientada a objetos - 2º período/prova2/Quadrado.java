package p2;

public class Quadrado extends Retangulo {
	
	@Override
	public void imprimir() {
		System.out.println("Area Quadrado = "+getArea()+ " Perimetro Quadrado = "+ getPerimetro());
	}
	public Quadrado(float l, float c) {
		super(l, c);
	}

}
