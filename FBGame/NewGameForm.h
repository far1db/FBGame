#pragma once
#include "Map.h"
#include "HighScore.h"

namespace FBGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Description résumée de NewGameForm
	/// </summary>
	public ref class NewGameForm : public System::Windows::Forms::Form
	{
	public:
		NewGameForm(void)
		{
			InitializeComponent();

			currentLevel = 0; // Default level
			levels = Directory::GetFiles("levels"); // Get the list of levels from the "levels" directory
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~NewGameForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::StatusStrip^  gameStatus;
	private: System::Windows::Forms::ToolStripStatusLabel^  coinsLabel;
	private: System::Windows::Forms::ToolStripStatusLabel^  levelLabel;
	private: System::Windows::Forms::ToolStripStatusLabel^  scoreLabel;
	private: System::Windows::Forms::ToolStripStatusLabel^  stepsLabel;
	private: System::Windows::Forms::ToolStripStatusLabel^  highestScoreLabel;

	protected:

	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(NewGameForm::typeid));
			this->gameStatus = (gcnew System::Windows::Forms::StatusStrip());
			this->coinsLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->stepsLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->scoreLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->levelLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->highestScoreLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->gameStatus->SuspendLayout();
			this->SuspendLayout();
			// 
			// gameStatus
			// 
			this->gameStatus->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->coinsLabel, this->stepsLabel,
					this->scoreLabel, this->highestScoreLabel, this->levelLabel
			});
			this->gameStatus->Location = System::Drawing::Point(0, 579);
			this->gameStatus->Name = L"gameStatus";
			this->gameStatus->Size = System::Drawing::Size(624, 22);
			this->gameStatus->TabIndex = 0;
			this->gameStatus->Text = L"statusStrip1";
			// 
			// coinsLabel
			// 
			this->coinsLabel->Name = L"coinsLabel";
			this->coinsLabel->Size = System::Drawing::Size(68, 17);
			this->coinsLabel->Text = L"Coins: N/M";
			// 
			// stepsLabel
			// 
			this->stepsLabel->Name = L"stepsLabel";
			this->stepsLabel->Size = System::Drawing::Size(66, 17);
			this->stepsLabel->Text = L"Steps: N/M";
			// 
			// scoreLabel
			// 
			this->scoreLabel->Name = L"scoreLabel";
			this->scoreLabel->Size = System::Drawing::Size(51, 17);
			this->scoreLabel->Text = L"Score: N";
			// 
			// levelLabel
			// 
			this->levelLabel->Name = L"levelLabel";
			this->levelLabel->Size = System::Drawing::Size(49, 17);
			this->levelLabel->Text = L"Level: N";
			// 
			// highestScoreLabel
			// 
			this->highestScoreLabel->Name = L"highestScoreLabel";
			this->highestScoreLabel->Size = System::Drawing::Size(83, 17);
			this->highestScoreLabel->Text = L"Highest Score:";
			// 
			// NewGameForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(624, 601);
			this->Controls->Add(this->gameStatus);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"NewGameForm";
			this->RightToLeftLayout = true;
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FBGame";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &NewGameForm::NewGameForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &NewGameForm::NewGameForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &NewGameForm::NewGameForm_KeyDown);
			this->gameStatus->ResumeLayout(false);
			this->gameStatus->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		Map map;
		array<String^>^ levels; // List of levels (inside the "levels" folder)
		int currentLevel;
		int previousScore; // The score earned from the previous level

		bool loadLevel(int);

	private: System::Void NewGameForm_Load(System::Object^  sender, System::EventArgs^  e) {

		

		// Check if there is at least one map in the "levels" folder
		if (levels->Length < 1) {
			MessageBox::Show("There is no level to load", "Error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
			Close();
		}
		else {
			// Load the current level | Display an error message and close the form if an error occured
			if (!loadLevel(currentLevel)) {
				MessageBox::Show("There was an error when loading the map", "Error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				Close();
			}
			else {
				map.show(this);
			}
		}
	}

	// Display the main menu when the game form is closed
	private: System::Void NewGameForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
		if (previousScore > HighScore::getHighScore()) {
			HighScore::setHighScore(previousScore);
		}

		Owner->Show();
	}

	// Handle Keyboard events
	private: System::Void NewGameForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		switch (e->KeyCode)
		{
		case Keys::Left:
			map.movePlayer(Directions::LEFT);
			break;
		case Keys::Right:
			map.movePlayer(Directions::RIGHT);
			break;
		case Keys::Up:
			map.movePlayer(Directions::UP);
			break;
		case Keys::Down:
			map.movePlayer(Directions::DOWN);
			break;
		}

		updateStatus();

		if (map.hasWon()) {
			previousScore = map.getScore(); // Save the score earned from this level

			// Check if this is the last level
			if (++currentLevel >= levels->Length) {
				MessageBox::Show("Bravo! You finished all the levels", "Bravo!", MessageBoxButtons::OK);

				Close();
			}
			else {
				System::Windows::Forms::DialogResult goOn = MessageBox::Show(
					"You successfully completed this level.\nDo you want to continue to the next level?",
					"Congratulations!",
					MessageBoxButtons::YesNo,
					MessageBoxIcon::Question
				);

				if (goOn == System::Windows::Forms::DialogResult::Yes) {
					loadLevel(currentLevel);
				}
				else {
					Close();
				}
			}
		}

		if (map.hasLost()) {
			// Remove the points earned froms this level
			// Reset to the previous score
			map.setScore(previousScore);

			System::Windows::Forms::DialogResult restart = MessageBox::Show(
				"You have exceeded the maximum number of steps!\nDo you want to restart this level?",
				"Lost!", 
				MessageBoxButtons::YesNo
			);

			if (restart == System::Windows::Forms::DialogResult::Yes) {
				loadLevel(currentLevel);
			}
			else {
				Close();
			}
		}
	}

	// Update the status bar
	private: void updateStatus();
};
}
