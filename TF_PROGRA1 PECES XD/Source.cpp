#include <iostream>
#include <conio.h>
using namespace std;
using namespace System;

struct pez {
	int x, dx, dy, y;
	bool muerto;
	int vuelta;
	bool catchable;

	pez(int x,int y, bool muerto=false)
	{
		this->x = x;
		this->y = y;
		this->muerto = muerto;
		vuelta = 1;
		dx = 1;
		catchable = true;
	}

	void setCatchable(bool catchable) { this->catchable = catchable; }

	void MostrarPez()
	{
		if (!muerto)
		{
			if (vuelta==1)
			{
				Console::SetCursorPosition(x, y);
				cout << "><>";
			}
			if (vuelta!=1)
			{
				Console::SetCursorPosition(x, y);
				cout << "<><";
			}
		}
	}

	void OcultarPez()
	{
		Console::SetCursorPosition(x, y);
		cout << "   ";
	}

	void setMuerto(bool muerto) { this->muerto = muerto; }

	void MoverPez()
	{
		OcultarPez();
		if (x < 2 || x >110)
		{
			dx *= -1;
			vuelta *= -1;
		}
		x += dx;
		MostrarPez();
	}

};

struct APez {
	pez **Arrpeces;
	int cant;

	APez()
	{
		Arrpeces = NULL;
		cant = 0;
	}
	~APez()
	{
		for (int i = 0; i < cant; i++)
		{
			delete Arrpeces[i];
		}
	}

	void AgregarPez(pez *dato)
	{
		pez **aux = new pez*[cant + 1];
		for (int i = 0; i < cant; i++)
		{
			aux[i] = Arrpeces[i];
		}
		aux[cant] = dato;
		Arrpeces = aux;
		cant = cant + 1;
	}

	void EliminarPez(pez *dato, int indice)
	{
		pez**aux = new pez*[cant];
		if (aux != nullptr)
		{
			for (int i = 0; i < cant; i++)
			{
				if (indice != i)
				{
					aux[i] = Arrpeces[i];
				}
			}
			aux[cant] = dato;
			cant--;
			if (Arrpeces != nullptr)
			{
				delete Arrpeces;
			}
			Arrpeces = aux;
		}
	}

	void MoverPeces()
	{
		for (int i = 0; i < cant; i++)
		{
			Arrpeces[i]->MoverPez();
			_sleep(20);
		}
	}

	pez *getPez(int i)
	{
		return Arrpeces[i];
	}

};

struct tiburon {
	int x, y, dx, dy;
	int vuelta;
	tiburon(int x, int y)
	{
		this->x = x;
		this->y = y;
		dx = 1;
		vuelta = 1;
	}

	void MostrarTiburon()
	{
		if (vuelta==1)
		{
			Console::SetCursorPosition(x, y);
			cout << "))===|�l>";
		}
		else
		{
			Console::SetCursorPosition(x, y);
			cout << "<l�|===((";
		}
	}
	void OcultarTiburon()
	{
		Console::SetCursorPosition(x, y);
		cout << "         ";
	}
	void MoverTiburon()
	{
		OcultarTiburon();
		if (x < 2 || x>100)
		{
			dx *= -1;
			vuelta *= -1;
		}
		x += dx;
		MostrarTiburon();
	}
};

struct ca�a {
	int x, y;
	int direccion;
	bool arrastrar;
	bool HasSomething;


	ca�a(int x, int y, bool arrastrar=false)
	{
		this->x = x;
		this->y = y;
		this->arrastrar = arrastrar;
		HasSomething = false;
	}

	void setHasSomething(bool HasSomething) { this->HasSomething = HasSomething; }

	void MostrarCa�a()
	{
		if (!arrastrar)
		{
			Console::SetCursorPosition(x, y);
			cout << "|";
		}
		if (arrastrar)
		{
			Console::SetCursorPosition(x, y);
			cout << "|";
			Console::SetCursorPosition(x, y + 1);
			cout << "><>";
		}
	}
	void BorrarCa�a()
	{
		if (!arrastrar)
		{
			Console::SetCursorPosition(x, y);
			cout << " ";
		}
		if (arrastrar)
		{
			Console::SetCursorPosition(x, y);
			cout << " ";
			Console::SetCursorPosition(x, y + 1);
			cout << "   ";
		}
	}

	void setArrastrar(bool arrastrar) { this->arrastrar = arrastrar; }

	void Mover()
	{
		if (direccion == 1) //derecha
			x++;
		if (direccion == 2)//izquierda
			x--;
		if (direccion == 3)//abajo
			y++;
		if (direccion == 4)//arriba
			y--;
	}



};

struct pescador {
	int x, y, vidas;
	ca�a *Sca�a;

	pescador(int x, int y, int vidas)
	{
		this->vidas = vidas;
		this->x = x;
		this->y = y;
		Sca�a = new ca�a(x+13, y+1);
	}

	void MostrarJugador()
	{
		Console::SetCursorPosition(x, y);
		cout << "O____________.";
		Console::SetCursorPosition(x, y + 1);
		cout << "l/\\\\";
	}

	void MoverCa�a()
	{
		Sca�a->BorrarCa�a();
		if (_kbhit())
		{
			char tecla = _getch();
			switch (tecla)
			{
			case 'a': Sca�a->direccion = 2; Sca�a->Mover(); break;
			case 'd':Sca�a->direccion = 1; Sca�a->Mover(); break;
			case 'w':Sca�a->direccion = 4; Sca�a->Mover(); break;
			case 's':Sca�a->direccion = 3; Sca�a->Mover(); break;
			default:break;
			}
		
		}
		Sca�a->MostrarCa�a();
	}

};

int main()
{
	Console::CursorVisible = false;
	pescador *jugador;
	
	
	int nivel = 1;

	
	jugador = new pescador(1, 1,3);



	int peces1 = 4;
	int peces2 = 8;
	int peces3 = 12;
	while (jugador->vidas > 0)
	{
		if (nivel == 1)
		{
			tiburon *objTiburon;
			objTiburon = new tiburon(3, 5);
			pez *objPez, *objPez2, *objPez3, *objPez4;
			APez *arreglopeces;
			arreglopeces = new APez();

			objPez = new pez(2, 10, false);
			objPez2 = new pez(4, 12, false);
			objPez3 = new pez(6, 15, false);
			objPez4 = new pez(5, 17, false);

			arreglopeces->AgregarPez(objPez);
			arreglopeces->AgregarPez(objPez2);
			arreglopeces->AgregarPez(objPez3);
			arreglopeces->AgregarPez(objPez4);

			while (jugador->vidas>0)
			{
				Console::SetCursorPosition(80, 1);
				cout << "Vidas: " << jugador->vidas << "  Peces: " << peces1 << " Tiburones: 1";

				Console::SetCursorPosition(6, 3);
				cout << "|_|";

				jugador->MostrarJugador();
				arreglopeces->MoverPeces();
				jugador->MoverCa�a();
				objTiburon->MoverTiburon();

				if (jugador->Sca�a->HasSomething == true)
				{
					jugador->Sca�a->BorrarCa�a();
					if (jugador->Sca�a->x < 6 && jugador->Sca�a->y > 3)
					{
						jugador->Sca�a->x++;
						jugador->Sca�a->y--;
					}
					if (jugador->Sca�a->x > 6 && jugador->Sca�a->y > 3)
					{
						jugador->Sca�a->x--;
						jugador->Sca�a->y--;
					}
					if (jugador->Sca�a->x == 6 && jugador->Sca�a->y > 3)
					{
						jugador->Sca�a->y--;
					}
					if (jugador->Sca�a->x == 6 && jugador->Sca�a->y < 3)
					{
						jugador->Sca�a->y++;
					}
					if (jugador->Sca�a->y == 3 && jugador->Sca�a->x < 6)
					{
						jugador->Sca�a->x++;
					}
					if (jugador->Sca�a->y == 3 && jugador->Sca�a->x > 6)
					{
						jugador->Sca�a->x--;
					}
					if (jugador->Sca�a->y == 3 && jugador->Sca�a->x == 6)
					{
						jugador->Sca�a->HasSomething = false;
					}
					jugador->Sca�a->MostrarCa�a();
				}



				for (int i = 0; i < arreglopeces->cant; i++)
				{
					if (arreglopeces->getPez(i)->x == jugador->Sca�a->x && arreglopeces->getPez(i)->y == jugador->Sca�a->y && arreglopeces->getPez(i)->catchable == true && jugador->Sca�a->HasSomething == false)
					{
						arreglopeces->getPez(i)->setMuerto(true);
						arreglopeces->getPez(i)->setCatchable(false);
						jugador->Sca�a->setArrastrar(true);
						jugador->Sca�a->setHasSomething(true);

					}
					if (jugador->Sca�a->x == 6 && jugador->Sca�a->y == 3 && jugador->Sca�a->arrastrar == true)
					{
						peces1--;
						jugador->Sca�a->arrastrar = false;
						jugador->Sca�a->setHasSomething(false);
					}

					if (jugador->Sca�a->x == objTiburon->x && jugador->Sca�a->y == objTiburon->y ||
						jugador->Sca�a->x == objTiburon->x + 1 && jugador->Sca�a->y == objTiburon->y ||
						jugador->Sca�a->x == objTiburon->x + 2 && jugador->Sca�a->y == objTiburon->y ||
						jugador->Sca�a->x == objTiburon->x + 3 && jugador->Sca�a->y == objTiburon->y ||
						jugador->Sca�a->x == objTiburon->x + 4 && jugador->Sca�a->y == objTiburon->y ||
						jugador->Sca�a->x == objTiburon->x + 5 && jugador->Sca�a->y == objTiburon->y ||
						jugador->Sca�a->x == objTiburon->x + 6 && jugador->Sca�a->y == objTiburon->y ||
						jugador->Sca�a->x == objTiburon->x + 7 && jugador->Sca�a->y == objTiburon->y ||
						jugador->Sca�a->x == objTiburon->x + 8 && jugador->Sca�a->y == objTiburon->y)
					{
						jugador->Sca�a->BorrarCa�a();
						if (jugador->Sca�a->arrastrar == true)
						{
							jugador->Sca�a->setArrastrar(false);
							jugador->Sca�a->HasSomething = false;
							jugador->vidas--;
							peces1--;
						}
					}
				}
				if (peces1 == 0)
				{
					Console::Clear();
					nivel++;
					break;
				}
				_sleep(50);
			}
		}

		if (nivel == 2)
		{
			APez * arreglopeces2 = new APez();
			tiburon *objTiburon = new tiburon(5, 4);
			tiburon *sTiburon = new tiburon(55, 5);

			pez *objPez5, *objPez6, *objPez7, *objPez8, *objPez9, *objPez10, *objPez11, *objPez12;

			objPez5 = new pez(8, 9, false);
			objPez6 = new pez(12, 11, false);
			objPez7 = new pez(13, 8, false);
			objPez8 = new pez(3, 15, false);
			objPez9 = new pez(4, 19, false);
			objPez10 = new pez(50, 28, false);
			objPez11 = new pez(87, 27, false);
			objPez12 = new pez(11, 22, false);

			arreglopeces2->AgregarPez(objPez5);
			arreglopeces2->AgregarPez(objPez6);
			arreglopeces2->AgregarPez(objPez7);
			arreglopeces2->AgregarPez(objPez8);
			arreglopeces2->AgregarPez(objPez9);
			arreglopeces2->AgregarPez(objPez10);
			arreglopeces2->AgregarPez(objPez11);
			arreglopeces2->AgregarPez(objPez12);

			while (jugador->vidas>0)
			{
				Console::SetCursorPosition(80, 1);
				cout << "Vidas: " << jugador->vidas << "  Peces: " << peces2 << " Tiburones: 2";

				Console::SetCursorPosition(6, 3);
				cout << "|_|";

				jugador->MostrarJugador();
				arreglopeces2->MoverPeces();
				jugador->MoverCa�a();
				objTiburon->MoverTiburon();
				sTiburon->MoverTiburon();

				if (jugador->Sca�a->HasSomething == true)
				{
					jugador->Sca�a->BorrarCa�a();
					if (jugador->Sca�a->x < 6 && jugador->Sca�a->y > 3)
					{
						jugador->Sca�a->x++;
						jugador->Sca�a->y--;
					}
					if (jugador->Sca�a->x > 6 && jugador->Sca�a->y > 3)
					{
						jugador->Sca�a->x--;
						jugador->Sca�a->y--;
					}
					if (jugador->Sca�a->x == 6 && jugador->Sca�a->y > 3)
					{
						jugador->Sca�a->y--;
					}
					if (jugador->Sca�a->x == 6 && jugador->Sca�a->y < 3)
					{
						jugador->Sca�a->y++;
					}
					if (jugador->Sca�a->y == 3 && jugador->Sca�a->x < 6)
					{
						jugador->Sca�a->x++;
					}
					if (jugador->Sca�a->y == 3 && jugador->Sca�a->x > 6)
					{
						jugador->Sca�a->x--;
					}
					if (jugador->Sca�a->y == 3 && jugador->Sca�a->x == 6)
					{
						jugador->Sca�a->HasSomething = false;
					}
					jugador->Sca�a->MostrarCa�a();
				}



				for (int i = 0; i < arreglopeces2->cant; i++)
				{
					if (arreglopeces2->getPez(i)->x == jugador->Sca�a->x && arreglopeces2->getPez(i)->y == jugador->Sca�a->y && arreglopeces2->getPez(i)->catchable == true && jugador->Sca�a->HasSomething == false)
					{
						arreglopeces2->getPez(i)->setMuerto(true);
						arreglopeces2->getPez(i)->setCatchable(false);
						jugador->Sca�a->setArrastrar(true);
						jugador->Sca�a->setHasSomething(true);

					}
					if (jugador->Sca�a->x == 6 && jugador->Sca�a->y == 3 && jugador->Sca�a->arrastrar == true)
					{
						peces2--;
						jugador->Sca�a->arrastrar = false;
						jugador->Sca�a->HasSomething = false;
					}

					if (jugador->Sca�a->x == objTiburon->x && jugador->Sca�a->y == objTiburon->y ||
						jugador->Sca�a->x == objTiburon->x + 1 && jugador->Sca�a->y == objTiburon->y ||
						jugador->Sca�a->x == objTiburon->x + 2 && jugador->Sca�a->y == objTiburon->y ||
						jugador->Sca�a->x == objTiburon->x + 3 && jugador->Sca�a->y == objTiburon->y ||
						jugador->Sca�a->x == objTiburon->x + 4 && jugador->Sca�a->y == objTiburon->y ||
						jugador->Sca�a->x == objTiburon->x + 5 && jugador->Sca�a->y == objTiburon->y ||
						jugador->Sca�a->x == objTiburon->x + 6 && jugador->Sca�a->y == objTiburon->y ||
						jugador->Sca�a->x == objTiburon->x + 7 && jugador->Sca�a->y == objTiburon->y ||
						jugador->Sca�a->x == objTiburon->x + 8 && jugador->Sca�a->y == objTiburon->y)
					{
						jugador->Sca�a->BorrarCa�a();
						if (jugador->Sca�a->arrastrar == true)
						{
							peces2--;
							jugador->Sca�a->setArrastrar(false);
							jugador->Sca�a->HasSomething = false;
							jugador->vidas--;
						}
					}
					if (jugador->Sca�a->x == sTiburon->x && jugador->Sca�a->y == sTiburon->y ||
						jugador->Sca�a->x == sTiburon->x + 1 && jugador->Sca�a->y == sTiburon->y ||
						jugador->Sca�a->x == sTiburon->x + 2 && jugador->Sca�a->y == sTiburon->y ||
						jugador->Sca�a->x == sTiburon->x + 3 && jugador->Sca�a->y == sTiburon->y ||
						jugador->Sca�a->x == sTiburon->x + 4 && jugador->Sca�a->y == sTiburon->y ||
						jugador->Sca�a->x == sTiburon->x + 5 && jugador->Sca�a->y == sTiburon->y ||
						jugador->Sca�a->x == sTiburon->x + 6 && jugador->Sca�a->y == sTiburon->y ||
						jugador->Sca�a->x == sTiburon->x + 7 && jugador->Sca�a->y == sTiburon->y ||
						jugador->Sca�a->x == sTiburon->x + 8 && jugador->Sca�a->y == sTiburon->y)
					{
						jugador->Sca�a->BorrarCa�a();
						if (jugador->Sca�a->arrastrar == true)
						{
							peces2--;
							jugador->Sca�a->setArrastrar(false);
							jugador->Sca�a->HasSomething = false;
							jugador->vidas--;
						}
					}

				}
				if (peces2 == 0)
				{
					Console::Clear();
					nivel++;
					break;
				}
				_sleep(50);
			}
		}

		if (nivel == 3)
		{
			tiburon *ssTiburon = new tiburon(4, 4);
			tiburon *sTiburon = new tiburon(60, 5);
			tiburon *objTiburon = new tiburon(100, 6);

			APez *arreglopeces3 = new APez();

			pez *objPez9, *objPez10, *objPez11, *objPez12, *objPez13, *objPez14, *objPez15, *objPez16, *objPez17, *objPez18, *objPez19, *objPez20;

			objPez9 = new pez(8, 9, false);
			objPez10 = new pez(12, 19, false);
			objPez11 = new pez(13, 22, false);
			objPez12 = new pez(3, 27, false);
			objPez13 = new pez(22, 23, false);
			objPez14 = new pez(25, 12, false);
			objPez15 = new pez(52, 15, false);
			objPez16 = new pez(48, 11, false);
			objPez17 = new pez(93, 19, false);
			objPez18 = new pez(23, 25, false);
			objPez19 = new pez(45, 9, false);
			objPez20 = new pez(12, 11, false);


			arreglopeces3->AgregarPez(objPez9);
			arreglopeces3->AgregarPez(objPez10);
			arreglopeces3->AgregarPez(objPez11);
			arreglopeces3->AgregarPez(objPez12);
			arreglopeces3->AgregarPez(objPez13);
			arreglopeces3->AgregarPez(objPez14);
			arreglopeces3->AgregarPez(objPez15);
			arreglopeces3->AgregarPez(objPez16);
			arreglopeces3->AgregarPez(objPez17);
			arreglopeces3->AgregarPez(objPez18);
			arreglopeces3->AgregarPez(objPez19);
			arreglopeces3->AgregarPez(objPez20);

			while (jugador->vidas>0)
			{
				Console::SetCursorPosition(6, 3);
				cout << "|_|";

				Console::SetCursorPosition(80, 1);
				cout << "Vidas: " << jugador->vidas<< "  Peces: " << peces3 << " Tiburones: 3";

				jugador->MostrarJugador();
				arreglopeces3->MoverPeces();
				jugador->MoverCa�a();
				objTiburon->MoverTiburon();
				sTiburon->MoverTiburon();
				ssTiburon->MoverTiburon();

				if (jugador->Sca�a->HasSomething == true)
				{
					jugador->Sca�a->BorrarCa�a();
					if (jugador->Sca�a->x < 6 && jugador->Sca�a->y > 3)
					{
						jugador->Sca�a->x++;
						jugador->Sca�a->y--;
					}
					if (jugador->Sca�a->x > 6 && jugador->Sca�a->y > 3)
					{
						jugador->Sca�a->x--;
						jugador->Sca�a->y--;
					}
					if (jugador->Sca�a->x == 6 && jugador->Sca�a->y > 3)
					{
						jugador->Sca�a->y--;
					}
					if (jugador->Sca�a->x == 6 && jugador->Sca�a->y < 3)
					{
						jugador->Sca�a->y++;
					}
					if (jugador->Sca�a->y == 3 && jugador->Sca�a->x < 6)
					{
						jugador->Sca�a->x++;
					}
					if (jugador->Sca�a->y == 3 && jugador->Sca�a->x > 6)
					{
						jugador->Sca�a->x--;
					}
					if (jugador->Sca�a->y == 3 && jugador->Sca�a->x == 6)
					{
						jugador->Sca�a->HasSomething = false;
					}
					jugador->Sca�a->MostrarCa�a();
				}



				for (int i = 0; i < arreglopeces3->cant; i++)
				{
					if (arreglopeces3->getPez(i)->x == jugador->Sca�a->x && arreglopeces3->getPez(i)->y == jugador->Sca�a->y && arreglopeces3->getPez(i)->catchable == true && jugador->Sca�a->HasSomething == false)
					{
						arreglopeces3->getPez(i)->setMuerto(true);
						arreglopeces3->getPez(i)->setCatchable(false);
						jugador->Sca�a->setArrastrar(true);
						jugador->Sca�a->HasSomething = true;
					}
					if (jugador->Sca�a->x == 6 && jugador->Sca�a->y == 3 && jugador->Sca�a->arrastrar == true)
					{
						peces3--;
						jugador->Sca�a->arrastrar = false;
						jugador->Sca�a->HasSomething = false;
					}
					if (jugador->Sca�a->x == objTiburon->x && jugador->Sca�a->y == objTiburon->y ||
						jugador->Sca�a->x == objTiburon->x + 1 && jugador->Sca�a->y == objTiburon->y ||
						jugador->Sca�a->x == objTiburon->x + 2 && jugador->Sca�a->y == objTiburon->y ||
						jugador->Sca�a->x == objTiburon->x + 3 && jugador->Sca�a->y == objTiburon->y ||
						jugador->Sca�a->x == objTiburon->x + 4 && jugador->Sca�a->y == objTiburon->y ||
						jugador->Sca�a->x == objTiburon->x + 5 && jugador->Sca�a->y == objTiburon->y ||
						jugador->Sca�a->x == objTiburon->x + 6 && jugador->Sca�a->y == objTiburon->y ||
						jugador->Sca�a->x == objTiburon->x + 7 && jugador->Sca�a->y == objTiburon->y ||
						jugador->Sca�a->x == objTiburon->x + 8 && jugador->Sca�a->y == objTiburon->y)
					{
						jugador->Sca�a->BorrarCa�a();
						if (jugador->Sca�a->arrastrar == true)
						{
							peces3--;
							jugador->Sca�a->setArrastrar(false);
							jugador->Sca�a->HasSomething = false;
							jugador->vidas--;
						}
					}
					if (jugador->Sca�a->x == sTiburon->x && jugador->Sca�a->y == sTiburon->y ||
						jugador->Sca�a->x == sTiburon->x + 1 && jugador->Sca�a->y == sTiburon->y ||
						jugador->Sca�a->x == sTiburon->x + 2 && jugador->Sca�a->y == sTiburon->y ||
						jugador->Sca�a->x == sTiburon->x + 3 && jugador->Sca�a->y == sTiburon->y ||
						jugador->Sca�a->x == sTiburon->x + 4 && jugador->Sca�a->y == sTiburon->y ||
						jugador->Sca�a->x == sTiburon->x + 5 && jugador->Sca�a->y == sTiburon->y ||
						jugador->Sca�a->x == sTiburon->x + 6 && jugador->Sca�a->y == sTiburon->y ||
						jugador->Sca�a->x == sTiburon->x + 7 && jugador->Sca�a->y == sTiburon->y ||
						jugador->Sca�a->x == sTiburon->x + 8 && jugador->Sca�a->y == sTiburon->y)
					{
						jugador->Sca�a->BorrarCa�a();
						if (jugador->Sca�a->arrastrar == true)
						{
							peces3--;
							jugador->Sca�a->setArrastrar(false);
							jugador->Sca�a->HasSomething = false;
							jugador->vidas--;
						}
					}
					if (jugador->Sca�a->x == ssTiburon->x && jugador->Sca�a->y == ssTiburon->y ||
						jugador->Sca�a->x == ssTiburon->x + 1 && jugador->Sca�a->y == ssTiburon->y ||
						jugador->Sca�a->x == ssTiburon->x + 2 && jugador->Sca�a->y == ssTiburon->y ||
						jugador->Sca�a->x == ssTiburon->x + 3 && jugador->Sca�a->y == ssTiburon->y ||
						jugador->Sca�a->x == ssTiburon->x + 4 && jugador->Sca�a->y == ssTiburon->y ||
						jugador->Sca�a->x == ssTiburon->x + 5 && jugador->Sca�a->y == ssTiburon->y ||
						jugador->Sca�a->x == ssTiburon->x + 6 && jugador->Sca�a->y == ssTiburon->y ||
						jugador->Sca�a->x == ssTiburon->x + 7 && jugador->Sca�a->y == ssTiburon->y ||
						jugador->Sca�a->x == ssTiburon->x + 8 && jugador->Sca�a->y == ssTiburon->y)
					{
						jugador->Sca�a->BorrarCa�a();
						if (jugador->Sca�a->arrastrar == true)
						{
							peces3--;
							jugador->Sca�a->setArrastrar(false);
							jugador->Sca�a->HasSomething = false;
							jugador->vidas--;
						}
					}
				}
				if (peces3 == 0)
				{
					Console::Clear();
					break;
				}
				_sleep(50);
			}
		}
	}

}