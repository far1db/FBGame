#pragma once
#include "NewGameForm.h"
#include "HowToPlayForm.h"

namespace FBGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form displaying the main menu of the game allowing the user to perform several actions
	/// </summary>
	public ref class MenuForm : public System::Windows::Forms::Form
	{
	public:
		MenuForm(void)
		{
			InitializeComponent();
			
			// Load the sound played on menu items hover
			menuHover = gcnew System::Media::SoundPlayer("sounds/menu-item-hover.wav");

			// Change the form client size to the background image size
			ClientSize = System::Drawing::Size(600, 600);
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonQuit;
	private: System::Windows::Forms::Button^  buttonNewGame;
	private: System::Windows::Forms::Button^  buttonHowToPlay;
	private: System::Windows::Forms::Button^  buttonHighestScore;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuForm::typeid));
			this->buttonQuit = (gcnew System::Windows::Forms::Button());
			this->buttonNewGame = (gcnew System::Windows::Forms::Button());
			this->buttonHowToPlay = (gcnew System::Windows::Forms::Button());
			this->buttonHighestScore = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// buttonQuit
			// 
			this->buttonQuit->BackColor = System::Drawing::Color::Transparent;
			this->buttonQuit->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonQuit.BackgroundImage")));
			this->buttonQuit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->buttonQuit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonQuit->FlatAppearance->BorderSize = 0;
			this->buttonQuit->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->buttonQuit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonQuit->Font = (gcnew System::Drawing::Font(L"Segoe Print", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonQuit->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(59)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->buttonQuit->Location = System::Drawing::Point(205, 492);
			this->buttonQuit->Name = L"buttonQuit";
			this->buttonQuit->Size = System::Drawing::Size(190, 45);
			this->buttonQuit->TabIndex = 1;
			this->buttonQuit->Text = L"Quit";
			this->buttonQuit->UseVisualStyleBackColor = false;
			this->buttonQuit->Click += gcnew System::EventHandler(this, &MenuForm::buttonQuit_Click);
			this->buttonQuit->MouseEnter += gcnew System::EventHandler(this, &MenuForm::buttonQuit_MouseEnter);
			this->buttonQuit->MouseLeave += gcnew System::EventHandler(this, &MenuForm::buttonQuit_MouseLeave);
			// 
			// buttonNewGame
			// 
			this->buttonNewGame->BackColor = System::Drawing::Color::Transparent;
			this->buttonNewGame->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonNewGame.BackgroundImage")));
			this->buttonNewGame->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->buttonNewGame->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonNewGame->FlatAppearance->BorderSize = 0;
			this->buttonNewGame->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonNewGame->Font = (gcnew System::Drawing::Font(L"Segoe Print", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonNewGame->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(72)), static_cast<System::Int32>(static_cast<System::Byte>(132)),
				static_cast<System::Int32>(static_cast<System::Byte>(44)));
			this->buttonNewGame->Location = System::Drawing::Point(205, 165);
			this->buttonNewGame->Name = L"buttonNewGame";
			this->buttonNewGame->Size = System::Drawing::Size(190, 45);
			this->buttonNewGame->TabIndex = 0;
			this->buttonNewGame->Text = L"New Game";
			this->buttonNewGame->UseVisualStyleBackColor = false;
			this->buttonNewGame->Click += gcnew System::EventHandler(this, &MenuForm::buttonNewGame_Click);
			this->buttonNewGame->MouseEnter += gcnew System::EventHandler(this, &MenuForm::buttonNewGame_MouseEnter);
			this->buttonNewGame->MouseLeave += gcnew System::EventHandler(this, &MenuForm::buttonNewGame_MouseLeave);
			// 
			// buttonHowToPlay
			// 
			this->buttonHowToPlay->BackColor = System::Drawing::Color::Transparent;
			this->buttonHowToPlay->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonHowToPlay.BackgroundImage")));
			this->buttonHowToPlay->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->buttonHowToPlay->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonHowToPlay->FlatAppearance->BorderSize = 0;
			this->buttonHowToPlay->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonHowToPlay->Font = (gcnew System::Drawing::Font(L"Segoe Print", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonHowToPlay->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(110)),
				static_cast<System::Int32>(static_cast<System::Byte>(147)));
			this->buttonHowToPlay->Location = System::Drawing::Point(205, 245);
			this->buttonHowToPlay->Name = L"buttonHowToPlay";
			this->buttonHowToPlay->Size = System::Drawing::Size(190, 45);
			this->buttonHowToPlay->TabIndex = 0;
			this->buttonHowToPlay->Text = L"How to play";
			this->buttonHowToPlay->UseVisualStyleBackColor = false;
			this->buttonHowToPlay->Click += gcnew System::EventHandler(this, &MenuForm::buttonHowToPlay_Click);
			this->buttonHowToPlay->MouseEnter += gcnew System::EventHandler(this, &MenuForm::buttonHowToPlay_MouseEnter);
			this->buttonHowToPlay->MouseLeave += gcnew System::EventHandler(this, &MenuForm::buttonHowToPlay_MouseLeave);
			// 
			// buttonHighestScore
			// 
			this->buttonHighestScore->BackColor = System::Drawing::Color::Transparent;
			this->buttonHighestScore->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonHighestScore.BackgroundImage")));
			this->buttonHighestScore->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->buttonHighestScore->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonHighestScore->FlatAppearance->BorderSize = 0;
			this->buttonHighestScore->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonHighestScore->Font = (gcnew System::Drawing::Font(L"Segoe Print", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonHighestScore->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)),
				static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(147)));
			this->buttonHighestScore->Location = System::Drawing::Point(205, 325);
			this->buttonHighestScore->Name = L"buttonHighestScore";
			this->buttonHighestScore->Size = System::Drawing::Size(190, 45);
			this->buttonHighestScore->TabIndex = 0;
			this->buttonHighestScore->Text = L"Highest Score";
			this->buttonHighestScore->UseVisualStyleBackColor = false;
			this->buttonHighestScore->Click += gcnew System::EventHandler(this, &MenuForm::buttonHighestScore_Click);
			this->buttonHighestScore->MouseEnter += gcnew System::EventHandler(this, &MenuForm::buttonHighestScore_MouseEnter);
			this->buttonHighestScore->MouseLeave += gcnew System::EventHandler(this, &MenuForm::buttonHighestScore_MouseLeave);
			// 
			// MenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(584, 561);
			this->Controls->Add(this->buttonHighestScore);
			this->Controls->Add(this->buttonHowToPlay);
			this->Controls->Add(this->buttonNewGame);
			this->Controls->Add(this->buttonQuit);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MenuForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FBGame";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MenuForm::MenuForm_FormClosed);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Media::SoundPlayer ^ menuHover;

	// What happens if the quit button is clicked
	private: System::Void buttonQuit_Click(System::Object^  sender, System::EventArgs^  e) {
		// Display confirmation dialog before exiting
		System::Windows::Forms::DialogResult confirmDialog = MessageBox::Show("Are you sure you want to quit the game?", "Quit?", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (confirmDialog == System::Windows::Forms::DialogResult::Yes) {
			Close();
		}
	}

	// Change The Background of the Quit button on mouse hover
	private: System::Void buttonQuit_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		buttonQuit->BackgroundImage = Image::FromFile("assets/red_button00.png");

		menuHover->Play();
	}
	private: System::Void buttonQuit_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		buttonQuit->BackgroundImage = Image::FromFile("assets/red_button02.png");
	}
	
	// Change The Background of the New Game button on mouse hover 
	private: System::Void buttonNewGame_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		buttonNewGame->BackgroundImage = Image::FromFile("assets/green_button03.png");

		menuHover->Play();
	}

	private: System::Void buttonNewGame_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		buttonNewGame->BackgroundImage = Image::FromFile("assets/green_button05.png");
	}

	// Create a New Game Form when the "New Game" button is clicked
	private: System::Void buttonNewGame_Click(System::Object^  sender, System::EventArgs^  e) {
		NewGameForm ^ newGameForm = gcnew NewGameForm;
		newGameForm->Show(this);
		// "this" which refers to the instance of this form is passed to newGameForm. 
		// Thus we can have access to the main menu form instance from the new game form. 

		// Hide the Menu Form
		Hide();
	}

	private: System::Void MenuForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
		// Quit the application when the menu form is closed
		Application::Exit();
	}

	private: System::Void buttonHowToPlay_Click(System::Object^  sender, System::EventArgs^  e) {
		HowToPlayForm ^ howToPlayForm = gcnew HowToPlayForm;
		howToPlayForm->Show(this);

		// Hide the Menu
		Hide();
	}
	private: System::Void buttonHowToPlay_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		buttonHowToPlay->BackgroundImage = Image::FromFile("assets/blue_button03.png");

		menuHover->Play();
	}
	private: System::Void buttonHowToPlay_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		buttonHowToPlay->BackgroundImage = Image::FromFile("assets/blue_button05.png");
	}

	// Display highest score
	private: System::Void buttonHighestScore_Click(System::Object^  sender, System::EventArgs^  e) {
		MessageBox::Show(
			"The highest score is: " + HighScore::getHighScore() + "\nCan you beat it?", 
			"Highest Score", 
			MessageBoxButtons::OK, 
			MessageBoxIcon::Information
		);
	}
	private: System::Void buttonHighestScore_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		buttonHighestScore->BackgroundImage = Image::FromFile("assets/blue_button03.png");

		menuHover->Play();
	}
	private: System::Void buttonHighestScore_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		buttonHighestScore->BackgroundImage = Image::FromFile("assets/blue_button05.png");
	}
};
}
