#pragma once

namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Message_Box에 대한 요약입니다.
	/// </summary>
	public ref class MessageBox : public System::Windows::Forms::Form
	{
	public:
		MessageBox(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//


		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~MessageBox()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::DataGridView^ dataGridView1;



	private: System::Windows::Forms::DataGridView^ dataGridView2;


	private: System::Windows::Forms::TextBox^ txtBoxMsg;





	private: System::Windows::Forms::Button^ btnRead;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ViewUnread;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Date;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ViewRead;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;

	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MessageBox::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->ViewUnread = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->ViewRead = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->txtBoxMsg = (gcnew System::Windows::Forms::TextBox());
			this->btnRead = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->ViewUnread,
					this->Date
			});
			this->dataGridView1->Location = System::Drawing::Point(56, 89);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 27;
			this->dataGridView1->Size = System::Drawing::Size(418, 204);
			this->dataGridView1->TabIndex = 2;
			// 
			// ViewUnread
			// 
			this->ViewUnread->HeaderText = L"From";
			this->ViewUnread->MinimumWidth = 6;
			this->ViewUnread->Name = L"ViewUnread";
			this->ViewUnread->Width = 125;
			// 
			// Date
			// 
			this->Date->HeaderText = L"Date";
			this->Date->MinimumWidth = 6;
			this->Date->Name = L"Date";
			this->Date->Width = 125;
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->ViewRead,
					this->dataGridViewTextBoxColumn2
			});
			this->dataGridView2->Location = System::Drawing::Point(56, 419);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 27;
			this->dataGridView2->Size = System::Drawing::Size(418, 204);
			this->dataGridView2->TabIndex = 4;
			// 
			// ViewRead
			// 
			this->ViewRead->HeaderText = L"From";
			this->ViewRead->MinimumWidth = 6;
			this->ViewRead->Name = L"ViewRead";
			this->ViewRead->Width = 125;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Date";
			this->dataGridViewTextBoxColumn2->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->Width = 125;
			// 
			// txtBoxMsg
			// 
			this->txtBoxMsg->Location = System::Drawing::Point(533, 89);
			this->txtBoxMsg->Multiline = true;
			this->txtBoxMsg->Name = L"txtBoxMsg";
			this->txtBoxMsg->Size = System::Drawing::Size(414, 535);
			this->txtBoxMsg->TabIndex = 8;
			// 
			// btnRead
			// 
			this->btnRead->BackColor = System::Drawing::Color::Transparent;
			this->btnRead->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnRead.BackgroundImage")));
			this->btnRead->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnRead->FlatAppearance->BorderSize = 0;
			this->btnRead->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnRead->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnRead->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRead->Location = System::Drawing::Point(240, 312);
			this->btnRead->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnRead->Name = L"btnRead";
			this->btnRead->Size = System::Drawing::Size(109, 44);
			this->btnRead->TabIndex = 9;
			this->btnRead->UseVisualStyleBackColor = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(365, 314);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(109, 38);
			this->button1->TabIndex = 9;
			this->button1->UseVisualStyleBackColor = false;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Transparent;
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(357, 629);
			this->button2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(109, 38);
			this->button2->TabIndex = 9;
			this->button2->UseVisualStyleBackColor = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 24));
			this->label3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label3->Location = System::Drawing::Point(48, 35);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(165, 46);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Unread";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 24));
			this->label1->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label1->Location = System::Drawing::Point(48, 370);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(122, 46);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Read";
			// 
			// btnClose
			// 
			this->btnClose->BackColor = System::Drawing::Color::Transparent;
			this->btnClose->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnClose.BackgroundImage")));
			this->btnClose->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnClose->FlatAppearance->BorderSize = 0;
			this->btnClose->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnClose->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClose->Location = System::Drawing::Point(801, 640);
			this->btnClose->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(146, 40);
			this->btnClose->TabIndex = 9;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &MessageBox::btnClose_Click);
			// 
			// MessageBox
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(982, 696);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btnRead);
			this->Controls->Add(this->txtBoxMsg);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->dataGridView1);
			this->DoubleBuffered = true;
			this->Name = L"MessageBox";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Message_Box";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Owner->Activate();
	this->Close();

}
};
}
