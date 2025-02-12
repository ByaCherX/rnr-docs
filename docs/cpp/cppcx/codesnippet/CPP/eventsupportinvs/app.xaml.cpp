﻿//
// App.xaml.cpp
// Implementation of the App class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace EventSupportinVS;

using namespace Platform;
using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Application template is documented at https://go.microsoft.com/fwlink/p/?linkid=234227

/// <summary>
/// Initializes the singleton application object.  This is the first line of authored code
/// executed, and as such is the logical equivalent of main() or WinMain().
/// </summary>
App::App()
{
    InitializeComponent();
    Suspending += ref new SuspendingEventHandler(this, &App::OnSuspending);
}

/// <summary>
/// Invoked when the application is launched normally by the end user.  Other entry points
/// will be used when the application is launched to open a specific file, to display
/// search results, and so forth.
/// </summary>
/// <param name="args">Details about the launch request and process.</param>
void App::OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ args)
{
    // Do not repeat app initialization when already running, just ensure that
    // the window is active
    if (args->PreviousExecutionState == ApplicationExecutionState::Running)
    {
        Window::Current->Activate();
        return;
    }

    if (args->PreviousExecutionState == ApplicationExecutionState::Terminated)
    {
        //TODO: Load state from previously suspended application
    }

    // Create a Frame to act navigation context and navigate to the first page
    auto rootFrame = ref new Frame();
    if (!rootFrame->Navigate(TypeName(MainPage::typeid)))
    {
        throw ref new FailureException("Failed to create initial page");
    }

    // Place the frame in the current Window and ensure that it is active
    Window::Current->Content = rootFrame;
    Window::Current->Activate();
}

/// <summary>
/// Invoked when application execution is being suspended.  Application state is saved
/// without knowing whether the application will be terminated or resumed with the contents
/// of memory still intact.
/// </summary>
/// <param name="sender">The source of the suspend request.</param>
/// <param name="e">Details about the suspend request.</param>
void App::OnSuspending(Object^ sender, SuspendingEventArgs^ e)
{
    (void) sender;    // Unused parameter
    (void) e;    // Unused parameter

    //TODO: Save application state and stop any background activity
}
