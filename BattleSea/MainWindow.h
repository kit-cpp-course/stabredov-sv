#pragma once
#include "Field.h"
namespace BattleSea {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	enum State {
		ST_SHIP_PLACEMENT,
		ST_USER_STEP,
		ST_ENEMY_STEP,
		ST_END
	};
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  radioButton6;
	private: System::Windows::Forms::RadioButton^  radioButton5;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ToolStripMenuItem^  играToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  новаяToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  СлучайнаяРасстановкаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  выйтиИзИгрыToolStripMenuItem1;
	public:

		int temp_orientation;//Параметры,
		int temp_type;       // необходимые для прорисовки
		int temp_x;			 // предварительного просмотра
		int temp_y;			 // на поле игрока

		Field* player;		//поле игрока
		Field* computer;	//поле компьютера
		int * ships;		//кол-во расставленных кораблей игрока
		Random^ rand;		//переменная получения случайного числа
		State state;		//текущее сцена игры
		//Код конструктора (Описывается в Header, т.к. этого требует среда разработки)
		MainWindow(void)
		{
			InitializeComponent();
			temp_orientation=0;
			temp_type=0;
			temp_x=0;
			temp_y=0;
			ships = new int[4];
			rand = gcnew Random();
			player = new Field();
			computer = new Field();
			richTextBox1->Text = "Расстановка кораблей";
			for (int i = 0; i < 4; i++)  ships[i] = 0;
			state = ST_SHIP_PLACEMENT;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		//освобождение памяти
		~MainWindow()
		{			
			delete[] player;
			delete[] computer;
			delete[] ships;
			delete rand;
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column9;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column10;
	private: System::Windows::Forms::DataGridView^  dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn9;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn10;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->играToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->новаяToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->СлучайнаяРасстановкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выйтиИзИгрыToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->ColumnHeadersVisible = false;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(10) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5, this->Column6, this->Column7, this->Column8, this->Column9, this->Column10
			});
			this->dataGridView1->Location = System::Drawing::Point(16, 33);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(297, 274);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->VirtualMode = true;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::dataGridView1_CellClick);
			this->dataGridView1->CellMouseMove += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &MainWindow::dataGridView1_CellMouseMove);
			this->dataGridView1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainWindow::dataGridView1_Paint);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Column1";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Width = 22;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Column2";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 22;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Column3";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Width = 22;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Column4";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->Width = 22;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Column5";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->Width = 22;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Column6";
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			this->Column6->Width = 22;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Column7";
			this->Column7->Name = L"Column7";
			this->Column7->ReadOnly = true;
			this->Column7->Width = 22;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"Column8";
			this->Column8->Name = L"Column8";
			this->Column8->ReadOnly = true;
			this->Column8->Width = 22;
			// 
			// Column9
			// 
			this->Column9->HeaderText = L"Column9";
			this->Column9->Name = L"Column9";
			this->Column9->ReadOnly = true;
			this->Column9->Width = 22;
			// 
			// Column10
			// 
			this->Column10->HeaderText = L"Column10";
			this->Column10->Name = L"Column10";
			this->Column10->ReadOnly = true;
			this->Column10->Width = 22;
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->AllowUserToResizeColumns = false;
			this->dataGridView2->AllowUserToResizeRows = false;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->ColumnHeadersVisible = false;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(10) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5,
					this->dataGridViewTextBoxColumn6, this->dataGridViewTextBoxColumn7, this->dataGridViewTextBoxColumn8, this->dataGridViewTextBoxColumn9,
					this->dataGridViewTextBoxColumn10
			});
			this->dataGridView2->Location = System::Drawing::Point(415, 33);
			this->dataGridView2->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView2->MultiSelect = false;
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->RowHeadersVisible = false;
			this->dataGridView2->Size = System::Drawing::Size(297, 274);
			this->dataGridView2->TabIndex = 1;
			this->dataGridView2->VirtualMode = true;
			this->dataGridView2->Visible = false;
			this->dataGridView2->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::dataGridView2_CellClick);
			this->dataGridView2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainWindow::dataGridView2_Paint);
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Column1";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			this->dataGridViewTextBoxColumn1->Width = 22;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Column2";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ReadOnly = true;
			this->dataGridViewTextBoxColumn2->Width = 22;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"Column3";
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->ReadOnly = true;
			this->dataGridViewTextBoxColumn3->Width = 22;
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"Column4";
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			this->dataGridViewTextBoxColumn4->ReadOnly = true;
			this->dataGridViewTextBoxColumn4->Width = 22;
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->HeaderText = L"Column5";
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			this->dataGridViewTextBoxColumn5->ReadOnly = true;
			this->dataGridViewTextBoxColumn5->Width = 22;
			// 
			// dataGridViewTextBoxColumn6
			// 
			this->dataGridViewTextBoxColumn6->HeaderText = L"Column6";
			this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
			this->dataGridViewTextBoxColumn6->ReadOnly = true;
			this->dataGridViewTextBoxColumn6->Width = 22;
			// 
			// dataGridViewTextBoxColumn7
			// 
			this->dataGridViewTextBoxColumn7->HeaderText = L"Column7";
			this->dataGridViewTextBoxColumn7->Name = L"dataGridViewTextBoxColumn7";
			this->dataGridViewTextBoxColumn7->ReadOnly = true;
			this->dataGridViewTextBoxColumn7->Width = 22;
			// 
			// dataGridViewTextBoxColumn8
			// 
			this->dataGridViewTextBoxColumn8->HeaderText = L"Column8";
			this->dataGridViewTextBoxColumn8->Name = L"dataGridViewTextBoxColumn8";
			this->dataGridViewTextBoxColumn8->ReadOnly = true;
			this->dataGridViewTextBoxColumn8->Width = 22;
			// 
			// dataGridViewTextBoxColumn9
			// 
			this->dataGridViewTextBoxColumn9->HeaderText = L"Column9";
			this->dataGridViewTextBoxColumn9->Name = L"dataGridViewTextBoxColumn9";
			this->dataGridViewTextBoxColumn9->ReadOnly = true;
			this->dataGridViewTextBoxColumn9->Width = 22;
			// 
			// dataGridViewTextBoxColumn10
			// 
			this->dataGridViewTextBoxColumn10->HeaderText = L"Column10";
			this->dataGridViewTextBoxColumn10->Name = L"dataGridViewTextBoxColumn10";
			this->dataGridViewTextBoxColumn10->ReadOnly = true;
			this->dataGridViewTextBoxColumn10->Width = 22;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(8, 23);
			this->radioButton1->Margin = System::Windows::Forms::Padding(4);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(126, 21);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"однопалубный";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(8, 52);
			this->radioButton2->Margin = System::Windows::Forms::Padding(4);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(122, 21);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"двухпалубный";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(8, 80);
			this->radioButton3->Margin = System::Windows::Forms::Padding(4);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(123, 21);
			this->radioButton3->TabIndex = 2;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"трехпалубный";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(8, 108);
			this->radioButton4->Margin = System::Windows::Forms::Padding(4);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(149, 21);
			this->radioButton4->TabIndex = 3;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"четырехпалубный";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->radioButton4);
			this->groupBox2->Controls->Add(this->radioButton3);
			this->groupBox2->Controls->Add(this->radioButton2);
			this->groupBox2->Controls->Add(this->radioButton1);
			this->groupBox2->Location = System::Drawing::Point(464, 33);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4);
			this->groupBox2->Size = System::Drawing::Size(168, 139);
			this->groupBox2->TabIndex = 0;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Тип коробля";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton6);
			this->groupBox1->Controls->Add(this->radioButton5);
			this->groupBox1->Location = System::Drawing::Point(464, 198);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->Size = System::Drawing::Size(165, 93);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Положение коробля";
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->Location = System::Drawing::Point(8, 52);
			this->radioButton6->Margin = System::Windows::Forms::Padding(4);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(123, 21);
			this->radioButton6->TabIndex = 1;
			this->radioButton6->Text = L"Вертикальное";
			this->radioButton6->UseVisualStyleBackColor = true;
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Checked = true;
			this->radioButton5->Location = System::Drawing::Point(8, 23);
			this->radioButton5->Margin = System::Windows::Forms::Padding(4);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(138, 21);
			this->radioButton5->TabIndex = 0;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"Горизонтальное";
			this->radioButton5->UseVisualStyleBackColor = true;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->играToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(8, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(721, 28);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// играToolStripMenuItem
			// 
			this->играToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->новаяToolStripMenuItem,
					this->СлучайнаяРасстановкаToolStripMenuItem, this->выйтиИзИгрыToolStripMenuItem1
			});
			this->играToolStripMenuItem->Name = L"играToolStripMenuItem";
			this->играToolStripMenuItem->Size = System::Drawing::Size(55, 24);
			this->играToolStripMenuItem->Text = L"Игра";
			// 
			// новаяToolStripMenuItem
			// 
			this->новаяToolStripMenuItem->Name = L"новаяToolStripMenuItem";
			this->новаяToolStripMenuItem->Size = System::Drawing::Size(248, 26);
			this->новаяToolStripMenuItem->Text = L"Новая игра";
			this->новаяToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::новаяToolStripMenuItem_Click);
			// 
			// СлучайнаяРасстановкаToolStripMenuItem
			// 
			this->СлучайнаяРасстановкаToolStripMenuItem->Name = L"СлучайнаяРасстановкаToolStripMenuItem";
			this->СлучайнаяРасстановкаToolStripMenuItem->Size = System::Drawing::Size(248, 26);
			this->СлучайнаяРасстановкаToolStripMenuItem->Text = L"Случайная расстановка";
			this->СлучайнаяРасстановкаToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::СлучайнаяРасстановкаToolStripMenuItem_Click);
			// 
			// выйтиИзИгрыToolStripMenuItem1
			// 
			this->выйтиИзИгрыToolStripMenuItem1->Name = L"выйтиИзИгрыToolStripMenuItem1";
			this->выйтиИзИгрыToolStripMenuItem1->Size = System::Drawing::Size(248, 26);
			this->выйтиИзИгрыToolStripMenuItem1->Text = L"Выйти из игры";
			this->выйтиИзИгрыToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainWindow::выйтиИзИгрыToolStripMenuItem1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::SystemColors::Control;
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox1->Location = System::Drawing::Point(0, 353);
			this->richTextBox1->Margin = System::Windows::Forms::Padding(4);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(318, 54);
			this->richTextBox1->TabIndex = 5;
			this->richTextBox1->Text = L"Расстановка кораблей";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(464, 346);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(184, 42);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Начать игру";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainWindow::button2_Click);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(721, 434);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->Name = L"MainWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Морской бой";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

   
private: 
bool flag();
            /*проверка или можно установить корабль в ячейку
			 *@params x,y - координаты ячейки
			 *@param orientation - положение корабля (0 - горизонтально, 1 - вертикально)
	 		 *@param type - тип корабля, 1-,2-,3- или 4-палубный
             *@param field - поле игрока или компьютера
			 */
System::Boolean checkSetShip(int x, int y, int orientation, int type, Field* field);
			 /*установка корабля в ячейку
			 *@params x,y - координаты ячейки
			 *@param orientation - положение корабля (0 - горизонтально, 1 - вертикально)
			 *@param type - стиль корабля, 1-,2-,3- или 4-палубный
			 *@param field- матрица расположения короблей игорока или компьютера
			 */
System::Boolean setShip(int x, int y, int orientation, int type, Field* field);
			 /*автоматическая расстановка кораблей на поле
			 *@param field - поле, на котором необходимо расставить корабли
			 */
System::Void autoSetShip(Field* field);
			 /*проверка,все ли корабли расставлены
			 *@param field - поле, которое необходимо проверить
			 */
System::Boolean checkShipPlacing(Field* field);
			/*проверка или корабль убит
			*/
System::Boolean cheсkShipKill(int x, int y, int xp, int yp, Field* field);
			 /*расстановка по кругу убитого корабля точек
			 */
System::Void shipKill(int x, int y, int xp, int yp, Field* field);
			 /*проверка или есть еще не убитые корабли
			 */
System::Boolean checkShipKillAll(Field* field);
			 //ход компьютера
System::Void pushComputer();
			 //действия при первоначальной загрузки формы
System::Void MainWindow_Load(System::Object^  sender, System::EventArgs^  e);
			 //ручная растановка кораблей на поле игрока
System::Void dataGridView1_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
			 //нажатие кнопки В БОЙ
 System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);
			 //нажатие по полю противника
System::Void dataGridView2_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
			 //прорисовка игрового поля игрока
System::Void dataGridView1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e);
			 //прорисовка игрового поля компьютера
System::Void dataGridView2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e);
			 //обработка нажатия кнопки "новая игра"
System::Void новаяToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
			 //обработка нажатия кнопки "случайная расстановка"
System::Void СлучайнаяРасстановкаToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
			 //обработка нажатия кнопки "выйти из игры"
System::Void выйтиИзИгрыToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e);
			 //обработка наведения курсора на поле игрока
System::Void dataGridView1_CellMouseMove(System::Object^  sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^  e);

};
}

