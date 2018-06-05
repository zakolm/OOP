#pragma once

#include "liftSystem.h"

namespace lab_04 {
    using namespace app;
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
    private: System::Windows::Forms::GroupBox^  gbButtons;
    //
	// Кнопка 3-го этажа
	//
	private: System::Windows::Forms::Button^  btn3;
    //
	// Кнопка 2-го этажа
	//
	private: System::Windows::Forms::Button^  btn2;
    //
	// Кнопка 1-го этажа
	//
	private: System::Windows::Forms::Button^  btn1;
    //
	// Кнопка 0-го этажа
	//
	private: System::Windows::Forms::Button^  btn0;
    private: System::Windows::Forms::GroupBox^  gbLabels;
    private: System::Windows::Forms::Label^  lblInfoDoor;
    private: System::Windows::Forms::Label^  lblDoor;
    private: System::Windows::Forms::Label^  lblInfoLift;
    private: System::Windows::Forms::Label^  lblLift;
    private: System::Windows::Forms::Label^  lblInfoController;
    private: System::Windows::Forms::Label^  lblController;
    private: System::Windows::Forms::Label^  lblClock;
    private: System::Windows::Forms::Timer^  tClock;
	//
	// Таймер движения лифта
	//
    private: System::Windows::Forms::Timer^  tLiftMove;
    private: System::Windows::Forms::Timer^  tDoorWork;
    private: System::Windows::Forms::Timer^  tDoorOpen;
    private: System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Обязательный метод для поддержки конструктора - не изменяйте
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            this->gbButtons = (gcnew System::Windows::Forms::GroupBox());
            this->btn3 = (gcnew System::Windows::Forms::Button());
            this->btn2 = (gcnew System::Windows::Forms::Button());
            this->btn1 = (gcnew System::Windows::Forms::Button());
            this->btn0 = (gcnew System::Windows::Forms::Button());
            this->gbLabels = (gcnew System::Windows::Forms::GroupBox());
            this->lblInfoDoor = (gcnew System::Windows::Forms::Label());
            this->lblDoor = (gcnew System::Windows::Forms::Label());
            this->lblInfoLift = (gcnew System::Windows::Forms::Label());
            this->lblLift = (gcnew System::Windows::Forms::Label());
            this->lblInfoController = (gcnew System::Windows::Forms::Label());
            this->lblController = (gcnew System::Windows::Forms::Label());
            this->lblClock = (gcnew System::Windows::Forms::Label());
            this->tClock = (gcnew System::Windows::Forms::Timer(this->components));
            this->tLiftMove = (gcnew System::Windows::Forms::Timer(this->components));
            this->tDoorWork = (gcnew System::Windows::Forms::Timer(this->components));
            this->tDoorOpen = (gcnew System::Windows::Forms::Timer(this->components));
            this->gbButtons->SuspendLayout();
            this->gbLabels->SuspendLayout();
            this->SuspendLayout();
            // 
            // gbButtons
            // 
            this->gbButtons->Controls->Add(this->btn3);
            this->gbButtons->Controls->Add(this->btn2);
            this->gbButtons->Controls->Add(this->btn1);
            this->gbButtons->Controls->Add(this->btn0);
            this->gbButtons->Location = System::Drawing::Point(18, 16);
            this->gbButtons->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
            this->gbButtons->Name = L"gbButtons";
            this->gbButtons->Padding = System::Windows::Forms::Padding(5, 4, 5, 4);
            this->gbButtons->Size = System::Drawing::Size(139, 271);
            this->gbButtons->TabIndex = 0;
            this->gbButtons->TabStop = false;
            this->gbButtons->Text = L"Этажи:";
            // 
            // btn3
            // 
            this->btn3->Location = System::Drawing::Point(8, 35);
            this->btn3->Name = L"btn3";
            this->btn3->Size = System::Drawing::Size(122, 52);
            this->btn3->TabIndex = 3;
            this->btn3->Text = L"3 - этаж";
            this->btn3->UseVisualStyleBackColor = true;
            this->btn3->Click += gcnew System::EventHandler(this, &MyForm::btn3_Click);
            // 
            // btn2
            // 
            this->btn2->Location = System::Drawing::Point(8, 93);
            this->btn2->Name = L"btn2";
            this->btn2->Size = System::Drawing::Size(122, 52);
            this->btn2->TabIndex = 2;
            this->btn2->Text = L"2 - этаж";
            this->btn2->UseVisualStyleBackColor = true;
            this->btn2->Click += gcnew System::EventHandler(this, &MyForm::btn2_Click);
            // 
            // btn1
            // 
            this->btn1->Location = System::Drawing::Point(8, 151);
            this->btn1->Name = L"btn1";
            this->btn1->Size = System::Drawing::Size(122, 52);
            this->btn1->TabIndex = 1;
            this->btn1->Text = L"1 - этаж";
            this->btn1->UseVisualStyleBackColor = true;
            this->btn1->Click += gcnew System::EventHandler(this, &MyForm::btn1_Click);
            // 
            // btn0
            // 
            this->btn0->Location = System::Drawing::Point(8, 209);
            this->btn0->Name = L"btn0";
            this->btn0->Size = System::Drawing::Size(122, 52);
            this->btn0->TabIndex = 0;
            this->btn0->Text = L"0 - этаж";
            this->btn0->UseVisualStyleBackColor = true;
            this->btn0->Click += gcnew System::EventHandler(this, &MyForm::btn0_Click);
            // 
            // gbLabels
            // 
            this->gbLabels->Controls->Add(this->lblInfoDoor);
            this->gbLabels->Controls->Add(this->lblDoor);
            this->gbLabels->Controls->Add(this->lblInfoLift);
            this->gbLabels->Controls->Add(this->lblLift);
            this->gbLabels->Controls->Add(this->lblInfoController);
            this->gbLabels->Controls->Add(this->lblController);
            this->gbLabels->Location = System::Drawing::Point(165, 16);
            this->gbLabels->Name = L"gbLabels";
            this->gbLabels->Size = System::Drawing::Size(367, 203);
            this->gbLabels->TabIndex = 1;
            this->gbLabels->TabStop = false;
            this->gbLabels->Text = L"Состояния:";
            // 
            // lblInfoDoor
            // 
            this->lblInfoDoor->AutoSize = true;
            this->lblInfoDoor->Location = System::Drawing::Point(151, 164);
            this->lblInfoDoor->Name = L"lblInfoDoor";
            this->lblInfoDoor->Size = System::Drawing::Size(70, 27);
            this->lblInfoDoor->TabIndex = 7;
            this->lblInfoDoor->Text = L"label3";
            // 
            // lblDoor
            // 
            this->lblDoor->AutoSize = true;
            this->lblDoor->Location = System::Drawing::Point(6, 164);
            this->lblDoor->Name = L"lblDoor";
            this->lblDoor->Size = System::Drawing::Size(81, 27);
            this->lblDoor->TabIndex = 6;
            this->lblDoor->Text = L"Двери:";
            // 
            // lblInfoLift
            // 
            this->lblInfoLift->AutoSize = true;
            this->lblInfoLift->Location = System::Drawing::Point(151, 106);
            this->lblInfoLift->Name = L"lblInfoLift";
            this->lblInfoLift->Size = System::Drawing::Size(70, 27);
            this->lblInfoLift->TabIndex = 5;
            this->lblInfoLift->Text = L"label1";
            // 
            // lblLift
            // 
            this->lblLift->AutoSize = true;
            this->lblLift->Location = System::Drawing::Point(6, 106);
            this->lblLift->Name = L"lblLift";
            this->lblLift->Size = System::Drawing::Size(73, 27);
            this->lblLift->TabIndex = 4;
            this->lblLift->Text = L"Лифт:";
            // 
            // lblInfoController
            // 
            this->lblInfoController->AutoSize = true;
            this->lblInfoController->Location = System::Drawing::Point(151, 48);
            this->lblInfoController->Name = L"lblInfoController";
            this->lblInfoController->Size = System::Drawing::Size(70, 27);
            this->lblInfoController->TabIndex = 3;
            this->lblInfoController->Text = L"label1";
            // 
            // lblController
            // 
            this->lblController->AutoSize = true;
            this->lblController->Location = System::Drawing::Point(6, 48);
            this->lblController->Name = L"lblController";
            this->lblController->Size = System::Drawing::Size(139, 27);
            this->lblController->TabIndex = 2;
            this->lblController->Text = L"Контроллер:";
            // 
            // lblClock
            // 
            this->lblClock->AutoSize = true;
            this->lblClock->Location = System::Drawing::Point(496, 260);
            this->lblClock->Name = L"lblClock";
            this->lblClock->Size = System::Drawing::Size(36, 27);
            this->lblClock->TabIndex = 2;
            this->lblClock->Text = L"[-]";
            // 
            // tClock
            // 
            this->tClock->Enabled = true;
            this->tClock->Interval = 1000;
            this->tClock->Tick += gcnew System::EventHandler(this, &MyForm::tClock_Tick);
            // 
            // tLiftMove
            // 
            this->tLiftMove->Tick += gcnew System::EventHandler(this, &MyForm::tLiftMove_Tick);
            // 
            // tDoorWork
            // 
            this->tDoorWork->Tick += gcnew System::EventHandler(this, &MyForm::tDoorWork_Tick);
            // 
            // tDoorOpen
            // 
            this->tDoorOpen->Tick += gcnew System::EventHandler(this, &MyForm::tDoorOpen_Tick);
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(13, 27);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(553, 301);
            this->Controls->Add(this->lblClock);
            this->Controls->Add(this->gbLabels);
            this->Controls->Add(this->gbButtons);
            this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
            this->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
            this->Name = L"MyForm";
            this->Text = L"MyForm";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->gbButtons->ResumeLayout(false);
            this->gbLabels->ResumeLayout(false);
            this->gbLabels->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
	//
	// Лифт
	//
    private: cLiftSys ^lift;
    private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e);
    private: System::Void btn0_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void btn1_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void btn2_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void btn3_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void tClock_Tick(System::Object^  sender, System::EventArgs^  e);
    private: System::Void tDoorWork_Tick(System::Object^  sender, System::EventArgs^  e) {
                 tDoorWork->Stop();
             }
    private: System::Void tDoorOpen_Tick(System::Object^  sender, System::EventArgs^  e) {
                 tDoorOpen->Stop();
             }
    private: System::Void tLiftMove_Tick(System::Object^  sender, System::EventArgs^  e) {
                 tLiftMove->Stop();
             }
    };
}
