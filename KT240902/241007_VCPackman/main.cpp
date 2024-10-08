// main.cpp
#include <wx/wx.h>

// Unsere eigene Klasse MyApp, die wxApp erbt
class MyApp : public wxApp
{
public:
    // Diese Methode wird beim Start der App aufgerufen
    virtual bool OnInit();
};

// Unsere eigene Klasse MyFrame, die wxFrame erbt
class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

private:
    void OnHello(wxCommandEvent& event);    // Event-Handler f¸r die "Hello"-Schaltfl‰che
    void OnExit(wxCommandEvent& event);     // Event-Handler f¸r das Beenden der App
    void OnAbout(wxCommandEvent& event);    // Event-Handler f¸r "‹ber"

    wxDECLARE_EVENT_TABLE();
};

// Event-Tabelle f¸r MyFrame
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MENU(wxID_EXIT, MyFrame::OnExit)
EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()

// Main App Implementierung
wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    // Erstellt das Hauptfenster (Frame)
    MyFrame* frame = new MyFrame("Hello World - wxWidgets", wxPoint(50, 50), wxSize(450, 340));
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    // Men¸leiste erstellen
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(wxID_EXIT);

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    // Statusleiste
    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

    // Schaltfl‰che hinzuf¸gen
    wxButton* btnHello = new wxButton(this, wxID_ANY, "Hello", wxPoint(10, 10), wxSize(100, 50));
    btnHello->Bind(wxEVT_BUTTON, &MyFrame::OnHello, this);
}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true); // Schlieﬂt das Fenster und beendet die Anwendung
}

void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello, wxWidgets!");
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("Dies ist eine wxWidgets 'Hello World' Anwendung",
        "‹ber Hello World", wxOK | wxICON_INFORMATION);
}