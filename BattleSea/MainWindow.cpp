#include "MainWindow.h"

using namespace BattleSea;

System::Boolean MainWindow::checkSetShip(int x, int y, int orientation, int type, Field* field) {
	bool res = true;
	if (orientation == 1)
		if (x + type <= 10)
		{
			int xn = x - 1;
			if (xn < 0) xn = 0;
			int xk = x + type;
			if (xk > 9) xk = 9;
			int yn = y - 1;
			if (yn < 0) yn = 0;
			int yk = y + 1;
			if (yk > 9) yk = 9;
			for (int i = xn; i <= xk; i++)
				for (int j = yn; j <= yk; j++)
					if (field->GetShip(i,j) == 1)
						res = false;
		}
		else
			res = false;
	if (orientation == 2)
		if (y + type <= 10)
		{
			int xn = x - 1;
			if (xn < 0) xn = 0;
			int xk = x + 1;
			if (xk > 9) xk = 9;
			int yn = y - 1;
			if (yn < 0) yn = 0;
			int yk = y + type;
			if (yk > 9) yk = 9;
			for (int i = xn; i <= xk; i++)
				for (int j = yn; j <= yk; j++)
					if (field->GetShip(i, j) == 1)
						res = false;
		}
		else
			res = false;
	return res;
}
System::Boolean MainWindow::setShip(int x, int y, int orientation, int type, Field* field) {
	bool res = false;
	if (checkSetShip(x, y, orientation, type, field))
	{
		if (orientation == 1)
			for (int i = x; i < x + type; i++)
				field->SetShip(i,y,C_SHIP);
		if (orientation == 2)
			for (int i = y; i < y + type; i++)
				field->SetShip(x,i, C_SHIP);
		res = true;
	}
	return res;
}
System::Void MainWindow::autoSetShip(Field* field) {
	for (int i = 1; i <= 4; i++)
	{
		int count = 0;
		int type = 5 - i;
		while (count != i)
		{
			int x = rand->Next(0, 10);
			int y = rand->Next(0, 10);
			int orientation = rand->Next(1, 3);
			if (setShip(x, y, orientation, type, field))
				count++;
		}
	}
}
System::Boolean MainWindow::checkShipPlacing(Field* field) {
	int count = 0;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (field->GetShip(i,j) == C_SHIP)
				count++;
	if (count == 20)
		return true;
	else
		return false;
}
System::Boolean MainWindow::cheÒkShipKill(int x, int y, int xp, int yp, Field* field) {
	bool res = true;
	if (x - 1 >= 0)
	{
		if (field->GetShip(x-1,y) == C_SHIP)
			res = false;
		if (field->GetShip(x-1, y) == C_BROKEN && x - 1 != xp)
			if (!cheÒkShipKill(x - 1, y, x, y, field))
				res = false;
	}
	if (x + 1 < 10)
	{
		if (field->GetShip(x + 1,y) == C_SHIP)
			res = false;
		if (field->GetShip(x + 1,y)==C_BROKEN && x + 1 != xp)
			if (!cheÒkShipKill(x + 1, y, x, y, field))
				res = false;
	}
	if (y - 1 >= 0)
	{
		if (field->GetShip(x,y-1) == C_SHIP)
			res = false;
		if (field->GetShip(x,y - 1) == C_BROKEN && y - 1 != yp)
			if (!cheÒkShipKill(x, y - 1, x, y, field))
				res = false;
	}
	if (y + 1 < 10)
	{
		if (field->GetShip(x,y + 1) == C_SHIP)
			res = false;
		if (field->GetShip(x,y + 1) == C_BROKEN && y + 1 != yp)
			if (!cheÒkShipKill(x, y + 1, x, y, field))
				res = false;
	}
	return res;
}
System::Void MainWindow::shipKill(int x, int y, int xp, int yp, Field* field) {
	if (x - 1 >= 0 && y - 1 >= 0)
		if (field->GetShip(x - 1,y-1) == C_EMPTY)
			field->SetShip(x - 1, y - 1,  C_DOT);
	if (x - 1 >= 0 && y + 1 < 10)
		if (field->GetShip(x - 1,y + 1) == C_EMPTY)
			field->SetShip(x - 1, y + 1,  C_DOT);
	if (x + 1 < 10 && y - 1 >= 0)
		if (field->GetShip( x + 1,y - 1) == C_EMPTY)
			field->SetShip(x + 1, y - 1, C_DOT);
	if (x + 1 < 10 && y + 1 < 10)
		if (field->GetShip(x + 1,y + 1) == C_EMPTY)
			field->SetShip(x + 1, y + 1, C_DOT);
	if (x - 1 >= 0)
	{
		if (field->GetShip(x - 1 ,y ) == C_EMPTY)
			field->SetShip(x - 1, y, C_DOT);
		if (field->GetShip(x - 1,y) == C_BROKEN && x - 1 != xp)
			shipKill(x - 1, y, x, y, field);
	}
	if (x + 1 < 10)
	{
		if (field->GetShip(x + 1,y ) == C_EMPTY)
			field->SetShip(x + 1, y, C_DOT);
		if (field->GetShip(x + 1,y ) == C_BROKEN && x + 1 != xp)
			shipKill(x + 1, y, x, y, field);
	}
	if (y - 1 >= 0)
	{
		if (field->GetShip(x,y - 1) == C_EMPTY)
			field->SetShip(x,y - 1, C_DOT);
		if (field->GetShip(x,y - 1) == C_BROKEN && y - 1 != yp)
			shipKill(x, y - 1, x, y, field);
	}
	if (y + 1 < 10)
	{
		if (field->GetShip(x,y + 1) == C_EMPTY)
			field->SetShip(x,y + 1, C_DOT);
		if (field->GetShip(x,y + 1) == C_BROKEN && y + 1 != yp)
			shipKill(x, y + 1, x, y, field);
	}
}
System::Boolean MainWindow::checkShipKillAll(Field* field) {
	bool res = true;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (field->GetShip(i,j) == C_SHIP)
				res = false;
	return res;
}
System::Void MainWindow::MainWindow_Load(System::Object^  sender, System::EventArgs^  e) {
	for (int i = 0; i < 10; i++)
	{
		dataGridView1->Rows->Add();
		dataGridView2->Rows->Add();
	}
	richTextBox1->SelectionAlignment = HorizontalAlignment::Center;
}
System::Void MainWindow::dataGridView1_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	if (state == ST_SHIP_PLACEMENT&&(!checkShipPlacing(player)))
	{
		int x = e->ColumnIndex;
		int y = e->RowIndex;
		int type;
		int orientation ;
		if (this->radioButton1->Checked) {
			type = 1;
		}
		else if (this->radioButton2->Checked) {
			type = 2;
		}
		else if (this->radioButton3->Checked) {
			type = 3;
		}
		else type = 4;

		if (radioButton5->Checked)
			orientation = 1;
		if (radioButton6->Checked)
			orientation = 2;
		if (type > 0)
		{
			if (setShip(x, y, orientation, type, player))
				ships[type - 1]++;

			if (ships[0] < 4)
				radioButton1->Enabled = true;
			else
			{
				radioButton1->Enabled = false;
				radioButton1->Checked = false;
				if(radioButton2->Enabled ==true&& ships[1] < 3) radioButton2->Checked = true;
				else if (radioButton3->Enabled == true && ships[2] < 2) radioButton3->Checked = true;
				else if (radioButton4->Enabled == true && ships[3] < 1) radioButton4->Checked = true;

			}
			if (ships[1] < 3)
				radioButton2->Enabled = true;
			else
			{
				radioButton2->Enabled = false;
				radioButton2->Checked = false;
				if (radioButton1->Enabled == true && ships[0] < 4) radioButton1->Checked = true;
				else if (radioButton3->Enabled == true && ships[2] < 2) radioButton3->Checked = true;
				else if (radioButton4->Enabled == true && ships[3] < 1) radioButton4->Checked = true;
			}
			if (ships[2] < 2)
				radioButton3->Enabled = true;
			else
			{
				radioButton3->Enabled = false;
				radioButton3->Checked = false;
				if (radioButton1->Enabled == true && ships[0] < 4) radioButton1->Checked = true;
				else if (radioButton2->Enabled == true && ships[1] < 3) radioButton2->Checked = true;
				else if (radioButton4->Enabled == true && ships[3] < 1) radioButton4->Checked = true;
			}
			if (ships[3] < 1)
				radioButton4->Enabled = true;
			else
			{
				radioButton4->Enabled = false;
				radioButton4->Checked = false;
				if (radioButton1->Enabled == true && ships[0] < 4) radioButton1->Checked = true;
				else if (radioButton2->Enabled == true && ships[1] < 3) radioButton2->Checked = true;
				else if (radioButton3->Enabled == true && ships[2] < 2) radioButton3->Checked = true;
			}
			if (checkShipPlacing(player)) {
				radioButton5->Checked = false;
				radioButton6->Checked = false;

				groupBox1->Enabled = false;
				groupBox2->Enabled = false;

			}
		}
	}
}
System::Void MainWindow::button2_Click(System::Object^  sender, System::EventArgs^  e) {
	if (checkShipPlacing(player))
	{
		autoSetShip(computer);
		groupBox1->Visible = false;
		groupBox2->Visible = false;
		button2->Enabled = false;
		dataGridView2->Visible = true;
		state = ST_USER_STEP;
		richTextBox1->Text = "¬‡¯ ıÓ‰!";
	}
}
System::Void MainWindow::dataGridView2_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	if (state == ST_USER_STEP)
	{
		int x = e->ColumnIndex;
		int y = e->RowIndex;
		//ÂÒÎË ÔÓÔ‡Î ‚ ÔÛÒÚÛ˛ ÍÎÂÚÍÛ
		if (computer->GetShip(x,y) == C_EMPTY )
		{
			richTextBox1->Text = "œÓÏ‡ı";
			computer->SetShip(x, y,C_DOT);
			pushComputer();
		}
		//ÂÒÎË ÔÓÔ‡Î ‚ ÍÓ‡·Î¸
		if (computer->GetShip(x, y) == C_SHIP)
		{
			computer->SetShip(x, y, C_BROKEN);
			if (cheÒkShipKill(x, y, x, y, computer))
			{
				richTextBox1->Text = "”·ËÎ";
				shipKill(x, y, x, y, computer);
			}
			else
				richTextBox1->Text = "–‡ÌËÎ";
		}

		//ÔÓ‚ÂÍ‡ ÓÍÓÌ˜‡ÌËˇ Ë„˚
		if (checkShipKillAll(player) || checkShipKillAll(computer))
		{
			state = ST_END;
			if (checkShipKillAll(player))
				richTextBox1->Text = "»„‡ ÓÍÓÌ˜ÂÌ‡! \n ¬˚ ÔÓË„‡ÎË!";
			if (checkShipKillAll(computer))
				richTextBox1->Text = "»„‡ ÓÍÓÌ˜ÂÌ‡! \n ¬˚ ‚˚Ë„‡ÎË!";
			if (checkShipKillAll(player) && checkShipKillAll(computer))
				richTextBox1->Text = "»„‡ ÓÍÓÌ˜ÂÌ‡! \n ÕË˜¸ˇ";
		}
	}
	dataGridView1->Refresh();
	dataGridView2->Refresh();
}
System::Void MainWindow::dataGridView1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			if (player->GetShip(i,j) == C_EMPTY)
			{
				dataGridView1[i, j]->Style->BackColor = Color::White;
				dataGridView1[i, j]->Style->SelectionBackColor = Color::White;
			}
			if (player->GetShip(i, j) == C_SHIP)
			{
				dataGridView1[i, j]->Style->BackColor = Color::Black;
				dataGridView1[i, j]->Style->SelectionBackColor = Color::Black;
			}
			if (player->GetShip(i, j) == C_DOT)
			{
				dataGridView1[i, j]->Style->SelectionBackColor = Color::White;
				Rectangle rect = dataGridView1->GetCellDisplayRectangle(i, j, true);
				SolidBrush^ brush = gcnew SolidBrush(Color::Black);
				Rectangle rect1 = Rectangle(rect.X + 8, rect.Y + 8, rect.Width - 16, rect.Height - 16);
				e->Graphics->FillRectangle(brush, rect1);
			}
			if (player->GetShip(i, j) == C_BROKEN)
			{
				dataGridView1[i, j]->Style->BackColor = Color::Red;
				dataGridView1[i, j]->Style->SelectionBackColor = Color::Red;
			}
			if (player->GetShip(i, j) == C_PREVIEW)
			{
				dataGridView1[i,j]->Style->BackColor = Color::Gray;
				dataGridView1[i,j]->Style->SelectionBackColor = Color::Gray;
			}
		}
}
System::Void MainWindow::dataGridView2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			if (computer->GetShip(i, j) == C_EMPTY || computer->GetShip(i, j) == C_SHIP)
			{
				dataGridView2[i, j]->Style->BackColor = Color::White;
				dataGridView2[i, j]->Style->SelectionBackColor = Color::White;
			}
			if (computer->GetShip(i, j) == C_DOT)
			{
				dataGridView2[i, j]->Style->SelectionBackColor = Color::White;
				Rectangle rect = dataGridView2->GetCellDisplayRectangle(i, j, true);
				SolidBrush^ brush = gcnew SolidBrush(Color::Green);
				Rectangle rect1 = Rectangle(rect.X + 8, rect.Y + 8, rect.Width - 16, rect.Height - 16);
				e->Graphics->FillRectangle(brush, rect1);
			}
			if (computer->GetShip(i, j) == C_BROKEN)
			{
				dataGridView2[i, j]->Style->BackColor = Color::Red;
				dataGridView2[i, j]->Style->SelectionBackColor = Color::Red;
			}
		}
}
System::Void MainWindow::ÌÓ‚‡ˇToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	ships = new int[4];
	rand = gcnew Random();
	player = new Field();
	computer = new Field();
	temp_orientation = 0;
	temp_type = 0;
	temp_x = 0;
	temp_y = 0;
	richTextBox1->Text = "–‡ÒÒÚ‡ÌÓ‚Í‡ ÍÓ‡·ÎÂÈ";
	for (int i = 0; i < 4; i++)  ships[i] = 0;
	state = ST_SHIP_PLACEMENT;
	dataGridView1->Refresh();
	dataGridView2->Refresh();
	dataGridView2->Visible = false;
	groupBox1->Enabled = true;
	groupBox2->Enabled = true;
	groupBox1->Visible = true;
	groupBox2->Visible = true;
	button2->Enabled = true;
	radioButton1->Checked = true;
	radioButton2->Checked = false;
	radioButton3->Checked = false;
	radioButton4->Checked = false;
	radioButton5->Checked = true;
	radioButton6->Checked = false;
	radioButton1->Enabled = true;
	radioButton2->Enabled = true;
	radioButton3->Enabled = true;
	radioButton4->Enabled = true;
	radioButton5->Enabled = true;
	radioButton6->Enabled = true;
}
System::Void MainWindow::—ÎÛ˜‡ÈÌ‡ˇ–‡ÒÒÚ‡ÌÓ‚Í‡ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	ships = new int[4];
	rand = gcnew Random();
	player = new Field();
	computer = new Field();
	richTextBox1->Text = "–‡ÒÒÚ‡ÌÓ‚Í‡ ÍÓ‡·ÎÂÈ";
	for (int i = 0; i < 4; i++)  ships[i] = 0;
	state = ST_SHIP_PLACEMENT;
	autoSetShip(player);
	dataGridView1->Refresh();
	radioButton1->Checked = false;
	radioButton2->Checked = false;
	radioButton3->Checked = false;
	radioButton4->Checked = false;
	radioButton5->Checked = false;
	radioButton6->Checked = false;
	groupBox1->Enabled = false;
	groupBox2->Enabled = false;
}
System::Void MainWindow::‚˚ÈÚË»Á»„˚ToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	Close();
}
System::Void MainWindow::pushComputer() {
	    state = ST_ENEMY_STEP;
	    bool flag;
		int x, xn, xk, y, yn, yk;
		xn = 0;
		xk = 10;
		yn = 0;
		yk = 10;
		do
		{
			x = rand->Next(xn, xk);
			y = rand->Next(yn, yk);
			if (player->GetShip(x,y) == C_DOT || player->GetShip(x, y) == C_BROKEN)
				flag = true;
			if (player->GetShip(x, y) == C_EMPTY)
			{
				player->SetShip(x, y,C_DOT);
				xn = 0;
				xk = 10;
				yn = 0;
				yk = 10;
				flag = false;
			}
			if (player->GetShip(x, y) == C_SHIP)
			{
				player->SetShip(x, y, C_BROKEN);

				if (cheÒkShipKill(x, y, x, y, player))
					shipKill(x, y, x, y, player);

				xn = x - 1;
				xk = x + 2;
				yn = y - 1;
				yk = y + 2;
				if (xn < 0) xn = 0;
				if (xk > 10) xk = 10;
				if (yn < 0) yn = 0;
				if (yk > 10) yk = 10;
				bool flag1 = true;
				for (int i = xn; i < xk; i++)
					for (int j = yn; j < yk; j++)
						if (player->GetShip(i,j) == C_EMPTY)
							flag1 = false;
				if (flag1)
				{
					xn = 0;
					xk = 10;
					yn = 0;
					yk = 10;
				}
				flag = true;
			}
			if (checkShipKillAll(player))
				flag = false;
		} while (flag);
		state = ST_USER_STEP;
}
bool MainWindow::flag() {
	if (temp_orientation == 1) {
		for (int i = 0; i < temp_type; i++)
		{
			if (player->GetShip(temp_x + i, temp_y) == C_SHIP) return true;
		}
	}
	else for (int i = 0; i < temp_type; i++) {
		if (player->GetShip(temp_x, temp_y + i) == C_SHIP) return true;
	}
}
System::Void MainWindow::dataGridView1_CellMouseMove(System::Object^  sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^  e) {
	if (!checkShipPlacing(player)) {
		int x = e->ColumnIndex;
		int y = e->RowIndex;
		int type;
		int orientation;
		if (this->radioButton1->Checked) {
			type = 1;
		}
		else if (this->radioButton2->Checked) {
			type = 2;
		}
		else if (this->radioButton3->Checked) {
			type = 3;
		}
		else type = 4;
		if (radioButton5->Checked)
		{
			orientation = 1;
		}
		else orientation = 2;

		if ((temp_orientation != orientation || temp_type != type || temp_x != x || temp_y != y)) {
			if (!flag()) {
				if (temp_orientation == 1) {
					for (int i = 0; i < temp_type; i++) {
						player->SetShip(temp_x + i, temp_y, C_EMPTY);
					}
				}
				else if (temp_y - 1 + temp_type < 10) {
					for (int i = 0; i < temp_type; i++) {
						player->SetShip(temp_x, temp_y + i, C_EMPTY);
					}
				}
			}
			temp_x = x;
			temp_y = y;
			temp_orientation = orientation;
			temp_type = type;
			if (!flag()) {
				if (temp_orientation == 1) {
					if (temp_x - 1 + temp_type < 10) {
						for (int i = 0; i < temp_type; i++) {
							player->SetShip(temp_x + i, temp_y, C_PREVIEW);
						}
					}
				}
				else if (temp_y - 1 + temp_type < 10) {
					for (int i = 0; i < temp_type; i++) {
						player->SetShip(temp_x, temp_y + i, C_PREVIEW);
					}
				}
				dataGridView1->Refresh();

			}
		}
	}
}


