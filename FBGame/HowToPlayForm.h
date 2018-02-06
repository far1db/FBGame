#pragma once

namespace FBGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de HowToPlayForm
	/// </summary>
	public ref class HowToPlayForm : public System::Windows::Forms::Form
	{
	public:
		HowToPlayForm(void)
		{
			InitializeComponent();
			
			ClientSize = System::Drawing::Size(600, 600);
			menuHover = gcnew System::Media::SoundPlayer("sounds/menu-item-hover.wav");
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~HowToPlayForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonBack;
	protected:

	protected:

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(HowToPlayForm::typeid));
			this->buttonBack = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// buttonBack
			// 
			this->buttonBack->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonBack.BackgroundImage")));
			this->buttonBack->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonBack->FlatAppearance->BorderSize = 0;
			this->buttonBack->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonBack->Font = (gcnew System::Drawing::Font(L"Segoe Print", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonBack->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(59)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->buttonBack->Location = System::Drawing::Point(48, 525);
			this->buttonBack->Name = L"buttonBack";
			this->buttonBack->Size = System::Drawing::Size(190, 45);
			this->buttonBack->TabIndex = 0;
			this->buttonBack->Text = L"Back";
			this->buttonBack->UseVisualStyleBackColor = true;
			this->buttonBack->Click += gcnew System::EventHandler(this, &HowToPlayForm::buttonBack_Click);
			this->buttonBack->MouseEnter += gcnew System::EventHandler(this, &HowToPlayForm::buttonBack_MouseEnter);
			this->buttonBack->MouseLeave += gcnew System::EventHandler(this, &HowToPlayForm::buttonBack_MouseLeave);
			// 
			// HowToPlayForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(623, 600);
			this->Controls->Add(this->buttonBack);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"HowToPlayForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FBGame - How To Play";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &HowToPlayForm::HowToPlayForm_FormClosed);
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Media::SoundPlayer ^ menuHover;

		private: System::Void HowToPlayForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			Owner->Show(); // Display the Main Menu
		}
		private: System::Void buttonBack_Click(System::Object^  sender, System::EventArgs^  e) {
			Close();
		}
		private: System::Void buttonBack_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
			buttonBack->BackgroundImage = Image::FromFile("assets/red_button00.png");
			menuHover->Play();
		}
		private: System::Void buttonBack_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			buttonBack->BackgroundImage = Image::FromFile("assets/red_button02.png");
		}
	};
}
