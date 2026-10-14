#include <wx/wx.h>

class HelloFrame final : public wxFrame {

public:
  HelloFrame() : wxFrame(nullptr, wxID_ANY, "wxWidgets Hello", wxDefaultPosition, wxSize(400, 180)) {
    auto* panel = new wxPanel(this);
    auto* layout = new wxBoxSizer(wxOrientation::wxVERTICAL);

    name_input_ = new wxTextCtrl(panel, wxID_ANY);
    auto* hello_button = new wxButton(panel, wxStandardID::wxID_ANY, "Say hello");

    layout->Add(new wxStaticText(panel, wxID_ANY, "Your name:"), 0, wxALL, 8);
    layout->Add(name_input_, 0, wxEXPAND | wxLEFT | wxRIGHT, 8);
    layout->Add(hello_button, 0, wxALL | wxALIGN_RIGHT, 8);

    panel->SetSizerAndFit(layout);
    hello_button->Bind(wxEVT_BUTTON, &HelloFrame::OnSayHello, this);
  }

private:
  void OnSayHello(wxCommandEvent&) {
    const wxString name = name_input_->GetValue().Trim(true).Trim(false);

    if (name.empty()) {
      wxMessageBox("Please enter your name.", "Hello", wxOK | wxICON_INFORMATION, this);
      return;
    }

    wxMessageBox("Hello, " + name + "!!", "Hello", wxOK | wxICON_INFORMATION, this);
  }

  wxTextCtrl* name_input_;
};

class HelloApp final : public wxApp {

public:
  bool OnInit() override {
    auto* frame = new HelloFrame();
    frame->Show(true);
    return true;
  }
};

wxIMPLEMENT_APP(HelloApp);

