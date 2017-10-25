#pragma once

#include "../LSWWin.h"
#include <map>
#include <string>

// == Macros.
#ifndef LSW_COUNT_OF
#define LSW_COUNT_OF(x)								((sizeof( x ) / sizeof( 0[x] )) / (static_cast<size_t>(!(sizeof( x ) % sizeof(0[x])))))
#define LSW_ELEMENTS( x )							LSW_COUNT_OF( x )
#endif	// #ifndef LSW_COUNT_OF

namespace lsw {

	class											CLayoutManager;

	class CBase {
	public :
		// == Functions.
		// =======================================
		// Create/Destroy.
		// =======================================
		// Initialize.
		static VOID									Initialize( HINSTANCE _hInst, CLayoutManager * _plmLayoutMan, const WCHAR * _pwcDockableClassName = nullptr );

		// Shut down (frees memory).
		static VOID									ShutDown();

		// =======================================
		// Windows/controls.
		// =======================================
		// Wrapper for ::RegisterClassEx().
		static ATOM									RegisterClassExW( const WNDCLASSEXW &_wceClss );

		// Gets the ATOM associated with a class registered via RegisterClassExW().
		static ATOM									GetRegisteredClassAtom( LPCWSTR _lpwcClass );

		// Gets the ATOM associated with a class registered via RegisterClassExW().
		static ATOM									GetRegisteredClassAtom( const std::wstring &_wsClass );

		// Gets the ATOM for dockable windows.
		static ATOM									DockableAtom() { return m_aDockable; }

		// =======================================
		// Process functions.
		// =======================================
		// Wrapper for ::GetModuleHandleW().
		static HMODULE								GetModuleHandleW( LPCWSTR _lpModuleName );

		// Wrapper for ::GetModuleHandleA().
		static HMODULE								GetModuleHandleA( LPCSTR _lpModuleName );

		// Gets the module handle for this executable.
		static HMODULE								GetThisHandle() { return m_hInstance; }

		// =======================================
		// Layouts.
		// =======================================
		// Gets the layout manager.
		static CLayoutManager *						LayoutManager() { return m_plmLayoutMan; }

		// =======================================
		// Error-related.
		// =======================================
		// Prints the current error (from ::GetLastError()).
		static VOID									PrintError( LPCWSTR _pwcText );

		// Displays a message box with the given title and message.
		static VOID									MessageBoxError( HWND _hWnd, LPCWSTR _pwcMsg, LPCWSTR _pwcTitle = L"Error" );

		// Displays a message box with the given title and message.
		static VOID									MessageBoxError( HWND _hWnd, LPCSTR _pcMsg, LPCSTR _pcTitle = "Error" );

		// =======================================
		// Fonts.
		// =======================================
		// Gets the default message-box font.
		static HFONT								MessageBoxFont() { return m_hMessageFont; }

		// Gets the default status-bar font.
		static HFONT								StatusBarFont() { return m_hStatusFont; }


	protected :
		// == Types.
		struct WNDCLASSEXW_ATOM : public WNDCLASSEXW {
			ATOM									aAtom;
		};

		// == Members.
		// Registered classes.
		static std::map<std::wstring, WNDCLASSEXW_ATOM>
													m_mClasses;

		// This HINSTANCE.
		static HINSTANCE							m_hInstance;

		// The layout manager.
		static CLayoutManager *						m_plmLayoutMan;

		// Non-client metrics.
		static NONCLIENTMETRICSW					m_ncmNonClientMetrics;

		// Message-box font.
		static HFONT								m_hMessageFont;

		// Status font.
		static HFONT								m_hStatusFont;

		// The dockable class.
		static ATOM									m_aDockable;
												
	};

}	// namespace lsw
