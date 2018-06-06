#pragma once

#include "sceneFacade.h"
#include "fileLoader.h"
#include "myProjector.h"
#include "commands.h"
#include <gcroot.h>

namespace lab_03 {
    static cSceneFacade facade;
    static gcroot<System::Drawing::Graphics^> canvas;

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Сводка для MyForm
    /// </summary>
    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            //
            //TODO: добавьте код конструктора
            //
        }

    protected:
        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Button^  button1;
    private: System::Windows::Forms::Button^  button2;
    private: System::Windows::Forms::Button^  button3;
    private: System::Windows::Forms::Button^  button4;
    private: System::Windows::Forms::Button^  button5;
    private: System::Windows::Forms::Button^  button6;
    private: System::Windows::Forms::PictureBox^  pictureBox1;
    protected: 

    private:
        /// <summary>
        /// Требуется переменная конструктора.
        /// </summary>
        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Обязательный метод для поддержки конструктора - не изменяйте
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        void InitializeComponent(void)
        {
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(633, 32);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(162, 51);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Загрузить модель";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(633, 89);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(162, 51);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Загрузка из файла";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(633, 226);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(162, 51);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Перемещение";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(633, 283);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(162, 51);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Масштабирование";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(633, 340);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(162, 51);
			this->button5->TabIndex = 5;
			this->button5->Text = L"Вращение";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(633, 433);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(162, 51);
			this->button6->TabIndex = 6;
			this->button6->Text = L"Камера";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Visible = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(581, 472);
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(823, 644);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
    private: System::Void updateCanvas(){
                 canvas->Clear(Color::White);

                 cMyProjector *proj = new cMyProjector();
                 cDrawerVs drawer(canvas, proj);
                 cDrawCommand cmd(drawer);
                 cmd.execute(facade);
             }
    private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
                 canvas = pictureBox1->CreateGraphics();
                 button6_Click(sender, e);
             }
    private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
                 try
                 {
                     cFileLoader loadImp("data.txt");
                     cModelBuilder builder;
                     cAbsLoader loader(&loadImp);
                     cLoadCommand cmd(loader, builder);
                     cmd.execute(facade);

                     updateCanvas();
                 }
                 catch (cBaseException &e)
                 {
                     std::cout << e.what() << std::endl;
                 }
             }
    private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
                 try
                 {
                     cFileLoader loadImp("newData.txt");
                     cAbsLoader loader(&loadImp);
                     objIterator iter = facade.createObjIterator("xxx");
                     cSaveCommand cmd(iter, loader);
                     cmd.execute(facade);
                 }
                 catch (cBaseException &e)
                 {
                     std::cout << e.what() << std::endl;
                 }
             }
    private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
                 try
                 {
                     objIterator iter = facade.createObjIterator("cube");
                     cShiftCommand cmd(10, 10, 10, iter);
                     cmd.execute(facade);

                     updateCanvas();
                 }
                 catch (cBaseException &e)
                 {
                     std::cout << e.what() << std::endl;
                 }
             }
    private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
                 try
                 {
                     objIterator iter = facade.createObjIterator("cube");
                     cScaleCommand cmd(2, 2, 1.5, iter);
                     cmd.execute(facade);

                     updateCanvas();
                 }
                 catch (cBaseException &e)
                 {
                     std::cout << e.what() << std::endl;
                 }
             }
    private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
                 try
                 {
                     objIterator iter = facade.createObjIterator("cube");
                     
                     cRotateXcommand cmd1(10, iter);
                     cmd1.execute(facade);
                     
                     cRotateYcommand cmd2(10, iter);
                     cmd2.execute(facade);
                     
                     cRotateZcommand cmd3(10, iter);
                     cmd3.execute(facade);

                     updateCanvas();
                 }
                 catch (cBaseException &e)
                 {
                     std::cout << e.what() << std::endl;
                 }
             }
    private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
                 cCamera* camera = new cCamera("camera");
                 cAddCameraCommand cmd(camera);
                 cmd.execute(facade);
             }
    };
}
