#pragma once
#include "Form2.h"
#include "Work.h"

namespace OOP
{
    using namespace System;
    using namespace System::Runtime::InteropServices;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class Form1 : public System::Windows::Forms::Form
    {
        public:
            Form1(void)
            {
                InitializeComponent();
            }
        protected:
            ~Form1()
            {
                if (components)
                {
                    delete components;
                }
            }
        private: System::Windows::Forms::PictureBox^  pictureBox1;
        private: System::Windows::Forms::Button^  button1;
        private: System::Windows::Forms::TextBox^  textBox1;
        private: System::Windows::Forms::TextBox^  textBox2;
        private: System::Windows::Forms::TextBox^  textBox3;
        private: System::Windows::Forms::TextBox^  textBox4;
        private: System::Windows::Forms::Button^  button2;
        private: System::Windows::Forms::Button^  button3;
        private: System::Windows::Forms::TextBox^  textBox5;
        private: System::Windows::Forms::TextBox^  textBox6;
        private: System::Windows::Forms::TextBox^  textBox7;
        private: System::Windows::Forms::Button^  button4;
        private: System::Windows::Forms::Label^  label1;
        private: System::Windows::Forms::Label^  label2;
        private: System::Windows::Forms::Label^  label3;
        private: System::Windows::Forms::Label^  label4;
        private: System::Windows::Forms::Label^  label5;
        private: System::Windows::Forms::Label^  label6;
        private: System::Windows::Forms::Label^  label7;
        private: System::Windows::Forms::Button^  button5;
        private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	private: System::ComponentModel::Container ^components;

    #pragma region Windows Form Designer generated code
            void InitializeComponent(void)
            {
				System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
				this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				this->button1 = (gcnew System::Windows::Forms::Button());
				this->textBox1 = (gcnew System::Windows::Forms::TextBox());
				this->textBox2 = (gcnew System::Windows::Forms::TextBox());
				this->textBox3 = (gcnew System::Windows::Forms::TextBox());
				this->textBox4 = (gcnew System::Windows::Forms::TextBox());
				this->button2 = (gcnew System::Windows::Forms::Button());
				this->button3 = (gcnew System::Windows::Forms::Button());
				this->textBox5 = (gcnew System::Windows::Forms::TextBox());
				this->textBox6 = (gcnew System::Windows::Forms::TextBox());
				this->textBox7 = (gcnew System::Windows::Forms::TextBox());
				this->button4 = (gcnew System::Windows::Forms::Button());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->label3 = (gcnew System::Windows::Forms::Label());
				this->label4 = (gcnew System::Windows::Forms::Label());
				this->label5 = (gcnew System::Windows::Forms::Label());
				this->label6 = (gcnew System::Windows::Forms::Label());
				this->label7 = (gcnew System::Windows::Forms::Label());
				this->button5 = (gcnew System::Windows::Forms::Button());
				this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
				this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
				this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
				this->toolStrip1->SuspendLayout();
				this->SuspendLayout();
				// 
				// pictureBox1
				// 
				this->pictureBox1->BackColor = System::Drawing::SystemColors::ActiveCaption;
				this->pictureBox1->Location = System::Drawing::Point(0, 0);
				this->pictureBox1->Name = L"pictureBox1";
				this->pictureBox1->Size = System::Drawing::Size(916, 691);
				this->pictureBox1->TabIndex = 0;
				this->pictureBox1->TabStop = false;
				// 
				// button1
				// 
				this->button1->Location = System::Drawing::Point(1031, 231);
				this->button1->Name = L"button1";
				this->button1->Size = System::Drawing::Size(129, 50);
				this->button1->TabIndex = 1;
				this->button1->Text = L"Поворот";
				this->button1->UseVisualStyleBackColor = true;
				this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
				// 
				// textBox1
				// 
				this->textBox1->Location = System::Drawing::Point(1031, 125);
				this->textBox1->Name = L"textBox1";
				this->textBox1->Size = System::Drawing::Size(129, 26);
				this->textBox1->TabIndex = 2;
				this->textBox1->Text = L"0";
				this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox1_KeyPress);
				// 
				// textBox2
				// 
				this->textBox2->Location = System::Drawing::Point(1031, 157);
				this->textBox2->Name = L"textBox2";
				this->textBox2->Size = System::Drawing::Size(129, 26);
				this->textBox2->TabIndex = 3;
				this->textBox2->Text = L"0";
				this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox2_KeyPress);
				// 
				// textBox3
				// 
				this->textBox3->Location = System::Drawing::Point(1031, 189);
				this->textBox3->Name = L"textBox3";
				this->textBox3->Size = System::Drawing::Size(129, 26);
				this->textBox3->TabIndex = 4;
				this->textBox3->Text = L"0";
				this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox3_KeyPress);
				// 
				// textBox4
				// 
				this->textBox4->Location = System::Drawing::Point(1031, 299);
				this->textBox4->Name = L"textBox4";
				this->textBox4->Size = System::Drawing::Size(129, 26);
				this->textBox4->TabIndex = 5;
				this->textBox4->Text = L"1";
				this->textBox4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox4_KeyPress);
				// 
				// button2
				// 
				this->button2->Location = System::Drawing::Point(1031, 345);
				this->button2->Name = L"button2";
				this->button2->Size = System::Drawing::Size(129, 50);
				this->button2->TabIndex = 6;
				this->button2->Text = L"Масштаб";
				this->button2->UseVisualStyleBackColor = true;
				this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
				// 
				// button3
				// 
				this->button3->Location = System::Drawing::Point(1031, 514);
				this->button3->Name = L"button3";
				this->button3->Size = System::Drawing::Size(129, 50);
				this->button3->TabIndex = 7;
				this->button3->Text = L"Смещение";
				this->button3->UseVisualStyleBackColor = true;
				this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
				// 
				// textBox5
				// 
				this->textBox5->Location = System::Drawing::Point(1031, 412);
				this->textBox5->Name = L"textBox5";
				this->textBox5->Size = System::Drawing::Size(129, 26);
				this->textBox5->TabIndex = 8;
				this->textBox5->Text = L"0";
				this->textBox5->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox5_KeyPress);
				// 
				// textBox6
				// 
				this->textBox6->Location = System::Drawing::Point(1031, 444);
				this->textBox6->Name = L"textBox6";
				this->textBox6->Size = System::Drawing::Size(129, 26);
				this->textBox6->TabIndex = 9;
				this->textBox6->Text = L"0";
				this->textBox6->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox6_KeyPress);
				// 
				// textBox7
				// 
				this->textBox7->Location = System::Drawing::Point(1031, 476);
				this->textBox7->Name = L"textBox7";
				this->textBox7->Size = System::Drawing::Size(129, 26);
				this->textBox7->TabIndex = 10;
				this->textBox7->Text = L"0";
				this->textBox7->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox7_KeyPress);
				// 
				// button4
				// 
				this->button4->Location = System::Drawing::Point(1031, 43);
				this->button4->Name = L"button4";
				this->button4->Size = System::Drawing::Size(129, 46);
				this->button4->TabIndex = 11;
				this->button4->Text = L"Модель";
				this->button4->UseVisualStyleBackColor = true;
				this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Location = System::Drawing::Point(963, 131);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(16, 20);
				this->label1->TabIndex = 12;
				this->label1->Text = L"x";
				// 
				// label2
				// 
				this->label2->AutoSize = true;
				this->label2->Location = System::Drawing::Point(963, 163);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(16, 20);
				this->label2->TabIndex = 13;
				this->label2->Text = L"y";
				// 
				// label3
				// 
				this->label3->AutoSize = true;
				this->label3->Location = System::Drawing::Point(963, 195);
				this->label3->Name = L"label3";
				this->label3->Size = System::Drawing::Size(17, 20);
				this->label3->TabIndex = 14;
				this->label3->Text = L"z";
				// 
				// label4
				// 
				this->label4->AutoSize = true;
				this->label4->Location = System::Drawing::Point(963, 305);
				this->label4->Name = L"label4";
				this->label4->Size = System::Drawing::Size(17, 20);
				this->label4->TabIndex = 15;
				this->label4->Text = L"k";
				// 
				// label5
				// 
				this->label5->AutoSize = true;
				this->label5->Location = System::Drawing::Point(964, 418);
				this->label5->Name = L"label5";
				this->label5->Size = System::Drawing::Size(16, 20);
				this->label5->TabIndex = 16;
				this->label5->Text = L"x";
				// 
				// label6
				// 
				this->label6->AutoSize = true;
				this->label6->Location = System::Drawing::Point(964, 450);
				this->label6->Name = L"label6";
				this->label6->Size = System::Drawing::Size(16, 20);
				this->label6->TabIndex = 17;
				this->label6->Text = L"y";
				// 
				// label7
				// 
				this->label7->AutoSize = true;
				this->label7->Location = System::Drawing::Point(964, 482);
				this->label7->Name = L"label7";
				this->label7->Size = System::Drawing::Size(17, 20);
				this->label7->TabIndex = 18;
				this->label7->Text = L"z";
				// 
				// button5
				// 
				this->button5->Location = System::Drawing::Point(1031, 629);
				this->button5->Name = L"button5";
				this->button5->Size = System::Drawing::Size(129, 50);
				this->button5->TabIndex = 19;
				this->button5->Text = L"Рисовать";
				this->button5->UseVisualStyleBackColor = true;
				this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
				// 
				// openFileDialog1
				// 
				this->openFileDialog1->FileName = L"openFileDialog1";
				this->openFileDialog1->Filter = L"txt files (*.txt)|*.txt";
				// 
				// toolStrip1
				// 
				this->toolStrip1->BackColor = System::Drawing::SystemColors::ButtonFace;
				this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripButton1});
				this->toolStrip1->Location = System::Drawing::Point(0, 0);
				this->toolStrip1->Name = L"toolStrip1";
				this->toolStrip1->Size = System::Drawing::Size(1196, 32);
				this->toolStrip1->TabIndex = 20;
				this->toolStrip1->Text = L"toolStrip1";
				// 
				// toolStripButton1
				// 
				this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
				this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton1.Image")));
				this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
				this->toolStripButton1->Name = L"toolStripButton1";
				this->toolStripButton1->Size = System::Drawing::Size(85, 29);
				this->toolStripButton1->Text = L"Справка";
				this->toolStripButton1->Click += gcnew System::EventHandler(this, &Form1::toolStripButton1_Click);
				// 
				// Form1
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->BackColor = System::Drawing::SystemColors::Control;
				this->ClientSize = System::Drawing::Size(1196, 691);
				this->Controls->Add(this->toolStrip1);
				this->Controls->Add(this->button5);
				this->Controls->Add(this->label7);
				this->Controls->Add(this->label6);
				this->Controls->Add(this->label5);
				this->Controls->Add(this->label4);
				this->Controls->Add(this->label3);
				this->Controls->Add(this->label2);
				this->Controls->Add(this->label1);
				this->Controls->Add(this->button4);
				this->Controls->Add(this->textBox7);
				this->Controls->Add(this->textBox6);
				this->Controls->Add(this->textBox5);
				this->Controls->Add(this->button3);
				this->Controls->Add(this->button2);
				this->Controls->Add(this->textBox4);
				this->Controls->Add(this->textBox3);
				this->Controls->Add(this->textBox2);
				this->Controls->Add(this->textBox1);
				this->Controls->Add(this->button1);
				this->Controls->Add(this->pictureBox1);
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
				this->MaximizeBox = false;
				this->MinimizeBox = false;
				this->Name = L"Form1";
				this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				this->Text = L"3D_Объект";
				this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
				this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
				this->toolStrip1->ResumeLayout(false);
				this->toolStrip1->PerformLayout();
				this->ResumeLayout(false);
				this->PerformLayout();

			}
    #pragma endregion
        private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
                {
                    input_mod_data_u change;
                    wrapper_canvas cont;
                    cont.pb = pictureBox1; //инициализируем обертку холста
                    change.canva = &cont;
                    Task_Manager(canvasInit, &change);
                }

        private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
                {
                    CodeError_e rc = OK;
                    if (this->openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
                    {
						input_mod_data_u change;
						change.filename = (char*)(void*)Marshal::StringToHGlobalAnsi(this->openFileDialog1->FileName);
						rc = Task_Manager(LoadModel, &change);
                    }
                    if (rc != OK)
						MessageBox::Show("Неверный файл!");
                }
        private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
                {
                    input_mod_data_u change = init_mod_data();
					if (textBox1->Text->Length && textBox2->Text->Length && textBox3->Text->Length)
					{
						change.data_rotate.angle_x = Convert::ToInt32(textBox1->Text);
						change.data_rotate.angle_y = Convert::ToInt32(textBox2->Text);
						change.data_rotate.angle_z = Convert::ToInt32(textBox3->Text);
						Task_Manager(RotateModel, &change);
					}
					else
						MessageBox::Show("Заполните все поля прежде чем делать поворот!");
                }
        private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
                {
                    input_mod_data_u change;
                    if (textBox4->Text->Length)
					{
						textBox4->Text = textBox4->Text->Replace(".", ",");
						change.data_scale = Convert::ToDouble(textBox4->Text);
						CodeError_e rc = Task_Manager(ScaleModel, &change);
						if (rc != OK)
							MessageBox::Show("Вырожденный случай!");
					}
					else
						MessageBox::Show("Заполните поле прежде чем изменять масштаб!");
                }
        private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
                {
					if (textBox5->Text->Length && textBox6->Text->Length && textBox7->Text->Length)
					{
						input_mod_data_u change;
						change.data_shift.dx = Convert::ToInt32(textBox5->Text);
						change.data_shift.dy = Convert::ToInt32(textBox6->Text);
						change.data_shift.dz = Convert::ToInt32(textBox7->Text);
						Task_Manager(ShiftModel, &change);
					}
					else
						MessageBox::Show("Заполните все поля прежде чем переместить объект!");
                }
        private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
                {
                    input_mod_data_u change;
                    Task_Manager(DeleteModel, &change);
                }
        private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e)
                {
                    input_mod_data_u change;
                    Task_Manager(ModelDraw, &change);
                }
	private: System::Void toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 Form2^ frm = gcnew Form2();
				 frm->ShowDialog();
			 }
private: System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
		 {
			 if (textBox1->Text->Length < 13)
			 {
				 if ((e->KeyChar >= '0') && (e->KeyChar <= '9'))
					 return;
				 if (e->KeyChar == ',' || e->KeyChar == '.')
				 {
					 MessageBox::Show("Можно изменять угол только на целочисленное значение!");
					 e->Handled = true;
				 }
				 if (e->KeyChar == '-' && textBox1->Text->Length == 0)
				 {
					 if (textBox1->Text->IndexOf('-') != -1)
						 e->Handled = true;
					 return;
				 }
			 }
			 if (Char::IsControl(e->KeyChar))
					 return;

			 e->Handled = true;
		 }
	private: System::Void textBox2_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
		 {
			 if (textBox2->Text->Length < 13)
			 {
				 if ((e->KeyChar >= '0') && (e->KeyChar <= '9'))
					 return;
				 if (e->KeyChar == ',' || e->KeyChar == '.')
				 {
					 MessageBox::Show("Можно изменять угол только на целочисленное значение!");
					 e->Handled = true;
				 }
				 if (e->KeyChar == '-' && textBox2->Text->Length == 0)
				 {
					 if (textBox2->Text->IndexOf('-') != -1)
						 e->Handled = true;
					 return;
				 }
			 }
			 if (Char::IsControl(e->KeyChar))
				 return;

			 e->Handled = true;
		 }
private: System::Void textBox3_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
		 {
			 if (textBox3->Text->Length < 13)
			 {
				 if ((e->KeyChar >= '0') && (e->KeyChar <= '9'))
					 return;
				 if (e->KeyChar == ',' || e->KeyChar == '.')
				 {
					 MessageBox::Show("Можно изменять угол только на целочисленное значение!");
					 e->Handled = true;
				 }
				 if (e->KeyChar == '-' && textBox3->Text->Length == 0)
				 {
					 if (textBox3->Text->IndexOf('-') != -1)
						 e->Handled = true;
					 return;
				 }
			 }
			 if (Char::IsControl(e->KeyChar))
					 return;

			 e->Handled = true;
		 }
private: System::Void textBox4_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
		 {
			 if (textBox4->Text->Length < 13)
			 {
				 if ((e->KeyChar >= '0') && (e->KeyChar <= '9'))
					 return;
				 if (e->KeyChar == ','|| e->KeyChar == '.')
				 {
					 if (textBox4->Text->IndexOf(',') != -1 ||  textBox4->Text->IndexOf('.') != -1 
						 || textBox4->Text->Length == 0)
						 e->Handled = true;
					 return;
				 }
			 }
			 if (Char::IsControl(e->KeyChar))
				 return;

			 e->Handled = true;
		 }
private: System::Void textBox5_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
		 {
			 if (textBox5->Text->Length < 13)
			 {
				 if ((e->KeyChar >= '0') && (e->KeyChar <= '9'))
					 return;
				 if (e->KeyChar == ',' || e->KeyChar == '.')
				 {
					 MessageBox::Show("Можно перемещать объект только на целочисленное значение!");
					 e->Handled = true;
				 }
				 if (e->KeyChar == '-' && textBox5->Text->Length == 0)
				 {
					 if (textBox5->Text->IndexOf('-') != -1)
						 e->Handled = true;
					 return;
				 }
			 }
			 if (Char::IsControl(e->KeyChar))
				 return;

			 e->Handled = true;
		 }
private: System::Void textBox6_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
		 {
			 if (textBox6->Text->Length < 13)
			 {
				 if ((e->KeyChar >= '0') && (e->KeyChar <= '9'))
					 return;
				 if (e->KeyChar == ',' || e->KeyChar == '.')
				 {
					 MessageBox::Show("Можно перемещать объект только на целочисленное значение!");
					 e->Handled = true;
				 }
				 if (e->KeyChar == '-' && textBox6->Text->Length == 0)
				 {
					 if (textBox6->Text->IndexOf('-') != -1)
						 e->Handled = true;
					 return;
				 }
			 }
			 if (Char::IsControl(e->KeyChar))
				 return;

			 e->Handled = true;
		 }
private: System::Void textBox7_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
		 {
			 if (textBox7->Text->Length < 13)
			 {
				 if ((e->KeyChar >= '0') && (e->KeyChar <= '9'))
					 return;
				 if (e->KeyChar == ',' || e->KeyChar == '.')
				 {
					 MessageBox::Show("Можно перемещать объект только на целочисленное значение!");
					 e->Handled = true;
				 }
				 if (e->KeyChar == '-' && textBox7->Text->Length == 0)
				 {
					 if (textBox7->Text->IndexOf('-') != -1)
						 e->Handled = true;
					 return;
				 }
			 }
			 if (Char::IsControl(e->KeyChar))
					 return;

			 e->Handled = true;
		 }
	};
}
