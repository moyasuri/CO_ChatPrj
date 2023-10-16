#pragma once

namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// DeleteChatRoom에 대한 요약입니다.
	/// </summary>
	public ref class DeleteChatRoom : public System::Windows::Forms::Form
	{
	public:
		DeleteChatRoom(void)
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
		~DeleteChatRoom()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ RoomName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CreateDate;
	private: System::Windows::Forms::Button^ button1;

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->RoomName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CreateDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->RoomName,
					this->CreateDate
			});
			this->dataGridView1->Location = System::Drawing::Point(51, 61);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 27;
			this->dataGridView1->Size = System::Drawing::Size(484, 316);
			this->dataGridView1->TabIndex = 0;
			// 
			// RoomName
			// 
			this->RoomName->HeaderText = L"RoomName";
			this->RoomName->MinimumWidth = 6;
			this->RoomName->Name = L"RoomName";
			this->RoomName->Width = 125;
			// 
			// CreateDate
			// 
			this->CreateDate->HeaderText = L"CreateDate";
			this->CreateDate->MinimumWidth = 6;
			this->CreateDate->Name = L"CreateDate";
			this->CreateDate->Width = 125;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(572, 71);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(157, 43);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Delete";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// DeleteChatRoom
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(760, 525);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"DeleteChatRoom";
			this->Text = L"DeleteChatRoom";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
