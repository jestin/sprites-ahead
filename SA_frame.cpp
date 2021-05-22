#include "SA_frame.h"
#include "editor_frame.h"
#include "SA_palette_frame.h"
#include "SA_create_palette_command.h"

#define ID_NEW_PALETTE 20001
#define ID_NEW_SPRITE 20002

wxBEGIN_EVENT_TABLE(SAFrame, wxDocMDIParentFrame)
	EVT_MENU(wxID_NEW, SAFrame::OnMenuNewProject)
	EVT_MENU(ID_NEW_PALETTE, SAFrame::OnMenuNewPalette)
	EVT_MENU(ID_NEW_SPRITE, SAFrame::OnMenuNewSprite)
	EVT_MENU(wxID_OPEN, SAFrame::OnMenuOpen)
	EVT_MENU(wxID_SAVE, SAFrame::OnMenuSave)
	EVT_MENU(wxID_ABOUT, SAFrame::OnMenuAbout)
	EVT_MENU(wxID_EXIT, SAFrame::OnMenuExit)
wxEND_EVENT_TABLE()

SAFrame::SAFrame(wxDocManager* pManager,
				wxFrame* pFrame,
				wxWindowID id,
				const wxString& title,
				const wxPoint& pos,
				const wxSize& size,
				long type)
	: wxDocMDIParentFrame(pManager, pFrame, id, title, pos, size, type)
{
	// create menus
	wxMenuBar *menuBar = new wxMenuBar;
	SetMenuBar(menuBar);

	wxMenu *menuFile = new wxMenu;
	menuFile->Append(wxID_NEW, "&New Project");
	menuFile->Append(ID_NEW_PALETTE, "New &Palette\tCtrl+P");
	menuFile->Append(ID_NEW_SPRITE, "New Spr&ite\tCtrl+Alt+S");
	menuFile->Append(wxID_OPEN, "&Open");
	menuFile->Append(wxID_SAVE, "&Save");
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);

	wxMenu *menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);

	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuHelp, "&Help");


	CreateStatusBar();
	SetStatusText("Welcome to Sprites Ahead!");
}

void SAFrame::OnMenuNewProject(wxCommandEvent& event)
{
}

void SAFrame::OnMenuNewSprite(wxCommandEvent& event)
{
	m_pView->OnCreateSprite(event);
}

void SAFrame::OnMenuNewPalette(wxCommandEvent& event)
{
	m_pView->OnCreatePalette(event);
}

void SAFrame::OnMenuOpen(wxCommandEvent& event)
{
}

void SAFrame::OnMenuSave(wxCommandEvent& event)
{
}

void SAFrame::OnMenuExit(wxCommandEvent& event)
{
	Close(true);
	event.Skip();
}

void SAFrame::OnMenuAbout(wxCommandEvent& event)
{
	wxMessageBox("If you have to ask, you're sprites behind",
			"About Sprites Ahead", wxOK | wxICON_INFORMATION);
	event.Skip();
}
