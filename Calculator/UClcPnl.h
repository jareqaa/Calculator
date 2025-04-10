#pragma once
#include "UControl.h"
#include <vector>
#include "Convertor.h"
#include <msclr/marshal_cppstd.h>
#include "AboutBox.h"

namespace Calculator
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for UClcPnl
	/// </summary>
	public ref class UClcPnl : public System::Windows::Forms::Form
	{
	public:
		UClcPnl(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UClcPnl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: TCtrl* ctrl = new TCtrl(TCtrl::PNumbers);
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Button^ button16;
	private: System::Windows::Forms::Button^ button17;
	private: System::Windows::Forms::Button^ button18;
	private: System::Windows::Forms::Button^ button19;
	private: System::Windows::Forms::Button^ button20;
	private: System::Windows::Forms::Button^ button21;
	private: System::Windows::Forms::Button^ button22;
	private: System::Windows::Forms::Button^ button23;
	private: System::Windows::Forms::Button^ button24;
	private: System::Windows::Forms::Button^ button25;
	private: System::Windows::Forms::Button^ button26;
	private: System::Windows::Forms::Button^ button27;
	private: System::Windows::Forms::Button^ button28;
	private: System::Windows::Forms::Button^ button29;
	private: System::Windows::Forms::Button^ button30;
	private: System::Windows::Forms::Button^ button33;
	private: System::Windows::Forms::Button^ button34;
	private: System::Windows::Forms::Button^ button35;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ справкаToolStripMenuItem;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
	private: System::Windows::Forms::Label^ label1;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->button26 = (gcnew System::Windows::Forms::Button());
			this->button27 = (gcnew System::Windows::Forms::Button());
			this->button28 = (gcnew System::Windows::Forms::Button());
			this->button29 = (gcnew System::Windows::Forms::Button());
			this->button30 = (gcnew System::Windows::Forms::Button());
			this->button33 = (gcnew System::Windows::Forms::Button());
			this->button34 = (gcnew System::Windows::Forms::Button());
			this->button35 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->справкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(12, 387);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(46, 46);
			this->button1->TabIndex = 0;
			this->button1->TabStop = false;
			this->button1->Tag = L"10";
			this->button1->Text = L"A";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(64, 387);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(46, 46);
			this->button2->TabIndex = 1;
			this->button2->TabStop = false;
			this->button2->Tag = L"11";
			this->button2->Text = L"B";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(116, 387);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(46, 46);
			this->button3->TabIndex = 2;
			this->button3->TabStop = false;
			this->button3->Tag = L"12";
			this->button3->Text = L"C";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button4
			// 
			this->button4->Enabled = false;
			this->button4->Location = System::Drawing::Point(168, 387);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(46, 46);
			this->button4->TabIndex = 3;
			this->button4->TabStop = false;
			this->button4->Tag = L"13";
			this->button4->Text = L"D";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button5
			// 
			this->button5->Enabled = false;
			this->button5->Location = System::Drawing::Point(220, 387);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(46, 46);
			this->button5->TabIndex = 4;
			this->button5->TabStop = false;
			this->button5->Tag = L"14";
			this->button5->Text = L"E";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button6
			// 
			this->button6->Enabled = false;
			this->button6->Location = System::Drawing::Point(272, 387);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(46, 46);
			this->button6->TabIndex = 5;
			this->button6->TabStop = false;
			this->button6->Tag = L"15";
			this->button6->Text = L"F";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(272, 335);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(46, 46);
			this->button7->TabIndex = 11;
			this->button7->TabStop = false;
			this->button7->Tag = L"25";
			this->button7->Text = L"=";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(220, 335);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(46, 46);
			this->button8->TabIndex = 10;
			this->button8->TabStop = false;
			this->button8->Tag = L"26";
			this->button8->Text = L"+";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(168, 335);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(46, 46);
			this->button9->TabIndex = 9;
			this->button9->TabStop = false;
			this->button9->Tag = L"17";
			this->button9->Text = L".";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(116, 335);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(46, 46);
			this->button10->TabIndex = 8;
			this->button10->TabStop = false;
			this->button10->Tag = L"16";
			this->button10->Text = L"+/-";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(64, 335);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(46, 46);
			this->button11->TabIndex = 7;
			this->button11->TabStop = false;
			this->button11->Tag = L"0";
			this->button11->Text = L"0";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button12
			// 
			this->button12->Enabled = false;
			this->button12->Location = System::Drawing::Point(12, 335);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(46, 46);
			this->button12->TabIndex = 6;
			this->button12->TabStop = false;
			this->button12->Tag = L"21";
			this->button12->Text = L"M+";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(220, 283);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(46, 46);
			this->button14->TabIndex = 16;
			this->button14->TabStop = false;
			this->button14->Tag = L"27";
			this->button14->Text = L"--";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(168, 283);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(46, 46);
			this->button15->TabIndex = 15;
			this->button15->TabStop = false;
			this->button15->Tag = L"3";
			this->button15->Text = L"3";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button16
			// 
			this->button16->Location = System::Drawing::Point(116, 283);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(46, 46);
			this->button16->TabIndex = 14;
			this->button16->TabStop = false;
			this->button16->Tag = L"2";
			this->button16->Text = L"2";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button17
			// 
			this->button17->Location = System::Drawing::Point(64, 283);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(46, 46);
			this->button17->TabIndex = 13;
			this->button17->TabStop = false;
			this->button17->Tag = L"1";
			this->button17->Text = L"1";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button18
			// 
			this->button18->Location = System::Drawing::Point(12, 283);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(46, 46);
			this->button18->TabIndex = 12;
			this->button18->TabStop = false;
			this->button18->Tag = L"22";
			this->button18->Text = L"MS";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button19
			// 
			this->button19->Location = System::Drawing::Point(272, 231);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(46, 46);
			this->button19->TabIndex = 23;
			this->button19->TabStop = false;
			this->button19->Tag = L"31";
			this->button19->Text = L"1/x";
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button20
			// 
			this->button20->Location = System::Drawing::Point(220, 231);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(46, 46);
			this->button20->TabIndex = 22;
			this->button20->TabStop = false;
			this->button20->Tag = L"28";
			this->button20->Text = L"*";
			this->button20->UseVisualStyleBackColor = true;
			this->button20->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button21
			// 
			this->button21->Location = System::Drawing::Point(168, 231);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(46, 46);
			this->button21->TabIndex = 21;
			this->button21->TabStop = false;
			this->button21->Tag = L"6";
			this->button21->Text = L"6";
			this->button21->UseVisualStyleBackColor = true;
			this->button21->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button22
			// 
			this->button22->Location = System::Drawing::Point(116, 231);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(46, 46);
			this->button22->TabIndex = 20;
			this->button22->TabStop = false;
			this->button22->Tag = L"5";
			this->button22->Text = L"5";
			this->button22->UseVisualStyleBackColor = true;
			this->button22->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button23
			// 
			this->button23->Location = System::Drawing::Point(64, 231);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(46, 46);
			this->button23->TabIndex = 19;
			this->button23->TabStop = false;
			this->button23->Tag = L"4";
			this->button23->Text = L"4";
			this->button23->UseVisualStyleBackColor = true;
			this->button23->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button24
			// 
			this->button24->Enabled = false;
			this->button24->Location = System::Drawing::Point(12, 231);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(46, 46);
			this->button24->TabIndex = 18;
			this->button24->TabStop = false;
			this->button24->Tag = L"23";
			this->button24->Text = L"MR";
			this->button24->UseVisualStyleBackColor = true;
			this->button24->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button25
			// 
			this->button25->Location = System::Drawing::Point(272, 179);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(46, 46);
			this->button25->TabIndex = 29;
			this->button25->TabStop = false;
			this->button25->Tag = L"30";
			this->button25->Text = L"Sqr";
			this->button25->UseVisualStyleBackColor = true;
			this->button25->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button26
			// 
			this->button26->Location = System::Drawing::Point(220, 179);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(46, 46);
			this->button26->TabIndex = 28;
			this->button26->TabStop = false;
			this->button26->Tag = L"29";
			this->button26->Text = L"/";
			this->button26->UseVisualStyleBackColor = true;
			this->button26->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button27
			// 
			this->button27->Location = System::Drawing::Point(168, 179);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(46, 46);
			this->button27->TabIndex = 27;
			this->button27->TabStop = false;
			this->button27->Tag = L"9";
			this->button27->Text = L"9";
			this->button27->UseVisualStyleBackColor = true;
			this->button27->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button28
			// 
			this->button28->Location = System::Drawing::Point(116, 179);
			this->button28->Name = L"button28";
			this->button28->Size = System::Drawing::Size(46, 46);
			this->button28->TabIndex = 26;
			this->button28->TabStop = false;
			this->button28->Tag = L"8";
			this->button28->Text = L"8";
			this->button28->UseVisualStyleBackColor = true;
			this->button28->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button29
			// 
			this->button29->Location = System::Drawing::Point(64, 179);
			this->button29->Name = L"button29";
			this->button29->Size = System::Drawing::Size(46, 46);
			this->button29->TabIndex = 25;
			this->button29->TabStop = false;
			this->button29->Tag = L"7";
			this->button29->Text = L"7";
			this->button29->UseVisualStyleBackColor = true;
			this->button29->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button30
			// 
			this->button30->Enabled = false;
			this->button30->Location = System::Drawing::Point(12, 179);
			this->button30->Name = L"button30";
			this->button30->Size = System::Drawing::Size(46, 46);
			this->button30->TabIndex = 24;
			this->button30->TabStop = false;
			this->button30->Tag = L"24";
			this->button30->Text = L"MC";
			this->button30->UseVisualStyleBackColor = true;
			this->button30->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button33
			// 
			this->button33->Location = System::Drawing::Point(220, 127);
			this->button33->Name = L"button33";
			this->button33->Size = System::Drawing::Size(98, 46);
			this->button33->TabIndex = 33;
			this->button33->TabStop = false;
			this->button33->Tag = L"20";
			this->button33->Text = L"C";
			this->button33->UseVisualStyleBackColor = true;
			this->button33->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button34
			// 
			this->button34->Location = System::Drawing::Point(116, 127);
			this->button34->Name = L"button34";
			this->button34->Size = System::Drawing::Size(98, 46);
			this->button34->TabIndex = 32;
			this->button34->TabStop = false;
			this->button34->Tag = L"19";
			this->button34->Text = L"CE";
			this->button34->UseVisualStyleBackColor = true;
			this->button34->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// button35
			// 
			this->button35->Location = System::Drawing::Point(12, 127);
			this->button35->Name = L"button35";
			this->button35->Size = System::Drawing::Size(98, 46);
			this->button35->TabIndex = 31;
			this->button35->TabStop = false;
			this->button35->Tag = L"18";
			this->button35->Text = L"BackSpace";
			this->button35->UseVisualStyleBackColor = true;
			this->button35->Click += gcnew System::EventHandler(this, &UClcPnl::button_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->справкаToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(330, 24);
			this->menuStrip1->TabIndex = 34;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// справкаToolStripMenuItem
			// 
			this->справкаToolStripMenuItem->Name = L"справкаToolStripMenuItem";
			this->справкаToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->справкаToolStripMenuItem->Text = L"Справка";
			this->справкаToolStripMenuItem->Click += gcnew System::EventHandler(this, &UClcPnl::справкаToolStripMenuItem_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(64, 439);
			this->trackBar1->Maximum = 16;
			this->trackBar1->Minimum = 2;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(254, 45);
			this->trackBar1->TabIndex = 35;
			this->trackBar1->TabStop = false;
			this->trackBar1->Tag = L"-1";
			this->trackBar1->Value = 10;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &UClcPnl::trackBar1_Scroll);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(12, 439);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 16, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->ReadOnly = true;
			this->numericUpDown1->Size = System::Drawing::Size(46, 20);
			this->numericUpDown1->TabIndex = 36;
			this->numericUpDown1->TabStop = false;
			this->numericUpDown1->Tag = L"-1";
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &UClcPnl::numericUpDown1_ValueChanged);
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(12, 27);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->textBox1->Size = System::Drawing::Size(306, 94);
			this->textBox1->TabIndex = 37;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(272, 283);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->ReadOnly = true;
			this->numericUpDown2->Size = System::Drawing::Size(46, 20);
			this->numericUpDown2->TabIndex = 38;
			this->numericUpDown2->TabStop = false;
			this->numericUpDown2->Tag = L"-1";
			this->numericUpDown2->ValueChanged += gcnew System::EventHandler(this, &UClcPnl::numericUpDown2_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(272, 306);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 13);
			this->label1->TabIndex = 39;
			this->label1->Text = L"точность";
			// 
			// UClcPnl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(330, 483);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->button33);
			this->Controls->Add(this->button34);
			this->Controls->Add(this->button35);
			this->Controls->Add(this->button25);
			this->Controls->Add(this->button26);
			this->Controls->Add(this->button27);
			this->Controls->Add(this->button28);
			this->Controls->Add(this->button29);
			this->Controls->Add(this->button30);
			this->Controls->Add(this->button19);
			this->Controls->Add(this->button20);
			this->Controls->Add(this->button21);
			this->Controls->Add(this->button22);
			this->Controls->Add(this->button23);
			this->Controls->Add(this->button24);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->button17);
			this->Controls->Add(this->button18);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"UClcPnl";
			this->Tag = L"-1";
			this->Text = L"Калькулятор";
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &UClcPnl::UClcPnl_KeyPress);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// отключить кнопки по тегу
	private: void DisableButtonsByTag(System::Windows::Forms::Control^ parent, int tagValue)
	{
		// проходим по всем элементам управления
		for each (System::Windows::Forms::Control ^ control in parent->Controls)
		{
			// проверяем, является ли элемент кнопкой
			System::Windows::Forms::Button^ button = dynamic_cast<System::Windows::Forms::Button^>(control);
			if (button != nullptr && button->Tag != nullptr)
			{
				System::Object^ tagV = button->Tag;	// получаем значение Tag
				System::String^ tagString = dynamic_cast<System::String^>(tagV); // преобразуем Tag в строку
				int currentTagValue = Convert::ToInt16(tagString);
				if (currentTagValue == tagValue)
				{
					button->Enabled = false;  // отключаем кнопку
				}
			}

			// рекурсивно проверяем дочерние элементы
			DisableButtonsByTag(control, tagValue);
		}
	}

		   // включить кнопки по тегу
	private: void EnableButtonsByTag(System::Windows::Forms::Control^ parent, int tagValue)
	{
		// проходим по всем элементам управления
		for each (System::Windows::Forms::Control ^ control in parent->Controls)
		{
			// проверяем, является ли элемент кнопкой
			System::Windows::Forms::Button^ button = dynamic_cast<System::Windows::Forms::Button^>(control);
			if (button != nullptr && button->Tag != nullptr)
			{
				// пытаемся привести Tag к int
				System::Object^ tagV = button->Tag;	// получаем значение Tag
				System::String^ tagString = dynamic_cast<System::String^>(tagV); // преобразуем Tag в строку
				int currentTagValue = Convert::ToInt16(tagString);
				if (currentTagValue == tagValue)
				{
					button->Enabled = true;  // включаем кнопку
				}
			}

			// рекурсивно проверяем дочерние элементы
			EnableButtonsByTag(control, tagValue);
		}
	}
		   // получение строки до последнего числа
	private: std::string ExtractNonNumericPrefix(const std::string& str) 
	{
		int pos = -1;
		for (int i = str.size() - 1; i >= 0; --i) 
		{
			if ((str[i] < '0' || str[i] > '9') && (str[i] < 'A' || str[i] > 'F') && str[i] != '.') 
			{
				pos = i;
				break;
			}
		}

		if (pos == -1) return "";

		std::string prefix = str.substr(0, pos + 1);
		if (!prefix.empty() && prefix.back() == '-') 
		{
			prefix.pop_back();
		}
		return prefix;
	}

		// обновление состояния кнопок
	private: void UpdateButtonStates(int currentBase) 
	{
		for (int i = 0; i < 16; i++) 
		{
			if (i < currentBase) 
			{
				EnableButtonsByTag(this, i);
			}
			else 
			{
				DisableButtonsByTag(this, i);
			}
		}
	}

		// обновление отоброжаемого числа
	private: void UpdateDisplay(int base, int precision) 
	{
		try 
		{
			std::string prefix = ExtractNonNumericPrefix(msclr::interop::marshal_as<std::string>(textBox1->Text));

			if (ctrl->getState() == ctrl->cEditing) 
			{
				double n = ctrl->getEdN();
				std::string number = Convertor::dbl_to_str(n, base, precision);
				textBox1->Text = gcnew String((prefix + number).c_str());
				ctrl->doClcCmd(100, number);
			}
			else if (ctrl->getState() == ctrl->cOpDone || ctrl->getState() == ctrl->FunDone) 
			{
				std::string number = ctrl->getNum();
				textBox1->Text = gcnew String((prefix + number).c_str());
				ctrl->doClcCmd(100, number);
			}
		}
		catch (const std::exception& err) 
		{
			ctrl->setCalcToStart(-1);
			MessageBox::Show(gcnew String(err.what()), "Error!", MessageBoxButtons::OK);
		}
	}

		// изменение системы счисления
	private: System::Void numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		int newBase = static_cast<int>(numericUpDown1->Value);
		trackBar1->Value = newBase;
		this->ActiveControl = nullptr;
		UpdateButtonStates(newBase);
		ctrl->setCC(newBase);
		UpdateDisplay(newBase, ctrl->getACC());
	}

		   // изменение системы счисления
	private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) 
	{
		int newBase = trackBar1->Value;
		numericUpDown1->Value = newBase;
		this->ActiveControl = nullptr;
		UpdateButtonStates(newBase);
		ctrl->setCC(newBase);
		UpdateDisplay(newBase, ctrl->getACC());
	}
		   // отключение/включение кнопок работы с памятью
	private: void updateMemBtns(System::Windows::Forms::Control^ parent, int tagValue)
	{
		// проходим по всем элементам управления
		for each(System::Windows::Forms::Control ^ control in parent->Controls)
		{
			// проверяем, является ли элемент кнопкой
			System::Windows::Forms::Button^ button = dynamic_cast<System::Windows::Forms::Button^>(control);
			if (button != nullptr && button->Tag != nullptr)
			{
				// пытаемся привести Tag к int
				System::Object^ tagV = button->Tag;	// получаем значение Tag
				System::String^ tagString = dynamic_cast<System::String^>(tagV); // преобразуем Tag в строку
				int currentTagValue = Convert::ToInt16(tagString);
				if (currentTagValue >= 21 && currentTagValue <= 24 && currentTagValue != 22)
				{
					if (tagValue == 24)
						button->Enabled = false;  // отключаем кнопку
					else
						button->Enabled = true;
				}
			}

			// рекурсивно проверяем дочерние элементы
			updateMemBtns(control, tagValue);
		}
	}
		   // обработка нажатия по кнопкам окна
	private: System::Void button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		System::Windows::Forms::Button^ button = dynamic_cast<System::Windows::Forms::Button^>(sender); // приводим sender к типу Button
		System::Object^ tagValue = button->Tag;	// получаем значение Tag
		System::String^ tagString = dynamic_cast<System::String^>(tagValue); // преобразуем Tag в строку
		int tag = Convert::ToInt16(tagString);
		this->ActiveControl = nullptr;
		try
		{
			std::string str = ctrl->doClcCmd(tag, "");
			if (str != "N")
			{
				textBox1->Text = gcnew String(str.c_str());
			}
			if (tag >= 21 && tag <= 24)
			{
				updateMemBtns(this, tag);
			}
		}
		catch (const std::exception& err)
		{
			ctrl->setCalcToStart(-1);
			MessageBox::Show(gcnew String(err.what()), "Error!", MessageBoxButtons::OK);
		}
	}

		   // обработка нажатий кнопок на клавиатуре
	private: System::Void UClcPnl_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		// обработка цифр(0 - 9)
		if (e->KeyChar >= '0' && e->KeyChar <= '9') 
		{
			if (Convertor::char_To_num(e->KeyChar) < ctrl->getCC())
			{
				try
				{
					textBox1->Text = gcnew String(ctrl->doClcCmd(Convertor::char_To_num(e->KeyChar), "").c_str());
				}
				catch (const std::exception& err)
				{
					ctrl->setCalcToStart(-1);
					MessageBox::Show(gcnew String(err.what()), "Error!", MessageBoxButtons::OK);
				}
			}
		}
		// обработка символов A, B, C, D, E, F
		else if (e->KeyChar >= 'A' && e->KeyChar <= 'F') 
		{
			if (Convertor::char_To_num(e->KeyChar) < ctrl->getCC())
			{
				try
				{
					textBox1->Text = gcnew String(ctrl->doClcCmd(Convertor::char_To_num(e->KeyChar), "").c_str());
				}
				catch (const std::exception& err)
				{
					ctrl->setCalcToStart(-1);
					MessageBox::Show(gcnew String(err.what()), "Error!", MessageBoxButtons::OK);
				}
			}
		}
		// обработка символов *, /, -, +, =
		else if (e->KeyChar == '*' || e->KeyChar == '/' || e->KeyChar == '-' || e->KeyChar == '+' || e->KeyChar == '=')
		{
			switch (e->KeyChar) 
			{
			case '*': textBox1->Text = gcnew String(ctrl->doClcCmd(28, "").c_str()); break;
			case '/': textBox1->Text = gcnew String(ctrl->doClcCmd(29, "").c_str()); break;
			case '-': textBox1->Text = gcnew String(ctrl->doClcCmd(27, "").c_str()); break;
			case '+': textBox1->Text = gcnew String(ctrl->doClcCmd(26, "").c_str()); break;
			case '=': textBox1->Text = gcnew String(ctrl->doClcCmd(25, "").c_str()); break;
			}
		}
		// обработка Enter
		else if (e->KeyChar == '\r') 
		{
			try
			{
				textBox1->Text = gcnew String(ctrl->doClcCmd(25, "").c_str());
			}
			catch (const std::exception& err)
			{
				ctrl->setCalcToStart(-1);
				MessageBox::Show(gcnew String(err.what()), "Error!", MessageBoxButtons::OK);
			}
			e->Handled = true;
		}
		// обработка Backspace
		else if (e->KeyChar == '\b') 
		{
			try
			{
				textBox1->Text = gcnew String(ctrl->doClcCmd(18, "").c_str());
			}
			catch (const std::exception& err)
			{
				ctrl->setCalcToStart(-1);
				MessageBox::Show(gcnew String(err.what()), "Error!", MessageBoxButtons::OK);
			}
			e->Handled = true;
		}
		// обработка .
		else if (e->KeyChar == '.')
		{
			try
			{
				textBox1->Text = gcnew String(ctrl->doClcCmd(17, "").c_str());
			}
			catch (const std::exception& err)
			{
				ctrl->setCalcToStart(-1);
				MessageBox::Show(gcnew String(err.what()), "Error!", MessageBoxButtons::OK);
			}
		}
		// игнорируем другие символы
		else 
		{
			e->Handled = true;
		}
	}

		   // изменение точности
	private: System::Void numericUpDown2_ValueChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		this->ActiveControl = nullptr;
		int newPrecision = static_cast<int>(numericUpDown2->Value);
		ctrl->setACC(newPrecision);
		UpdateDisplay(ctrl->getCC(), newPrecision);
	}
		   // нажатие на кнопку справка
	private: System::Void справкаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		AboutBox^ aboutBox = gcnew AboutBox();
		aboutBox->Show();	// открытие формы справки
	}
};
}
