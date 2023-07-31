package p2;

public class TesteDeDownCasting {

	public static void main(String[] args) {
		Quadrado q = new Quadrado(2,2);
		Retangulo r = new Retangulo(2,2);
		Circulo c = new Circulo(2,2);
		Elipse e = new Elipse(3,2);
		q.calcArea();
		r.calcArea();
		c.calcArea();
		e.calcArea();
		q.calcPerimetro();
		r.calcPerimetro();
		c.calcPerimetro();
		e.calcPerimetro();
		q.imprimir();
		r.imprimir();
		c.imprimir();
		e.imprimir();
	}
}
