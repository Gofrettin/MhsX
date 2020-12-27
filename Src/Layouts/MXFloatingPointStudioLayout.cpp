#include "MXFloatingPointStudioLayout.h"
#include "../FloatingPointStudio/MXFloatingPointStudioWindow.h"
#include "../Strings/MXStringDecoder.h"
#include "MXLayoutMacros.h"
#include "MXLayoutManager.h"

#include <Base/LSWBase.h>

namespace mx {

#define MX_FPS_W				(65*(15-MX_FPS_CHECKBOX_TRIM*2))+(8*2)
#define MX_FPS_H				340
	// == Members.
	// The layout for the PE Works window.
	LSW_WIDGET_LAYOUT CFloatingPointStudioLayout::m_wlMainWindow[] = {
		{
			MX_FLOATING_POINT_STUDIO,				// ltType
			MX_C_MAINWINDOW,						// wId
			nullptr,								// lpwcClass
			TRUE,									// bEnabled
			TRUE,									// bActive
			35,										// iLeft
			25,										// iTop
			MX_FPS_W,								// dwWidth
			MX_FPS_H,								// dwHeight
			WS_CAPTION | WS_POPUP | WS_VISIBLE | WS_CLIPSIBLINGS | WS_SYSMENU | DS_3DLOOK | DS_FIXEDSYS | DS_MODALFRAME | DS_CENTER,					// dwStyle
			WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR | WS_EX_WINDOWEDGE | WS_EX_CONTROLPARENT,												// dwStyleEx
			MX_MAKE_WCHAR( _T_830F43B3_Floating_Point_Studio ),																							// pwcText
			_LEN_830F43B3,							// sTextLen
			MX_C_NONE,								// dwParentId
			/*
			MX_PARENT_VCLEFT,						// pcLeftSizeExp
			MX_PARENT_VCRIGHT,						// pcRightSizeExp
			MX_PARENT_VCTOP,						// pcTopSizeExp
			MX_PARENT_VCBOTTOM,						// pcBottomSizeExp
			nullptr, 0,								// pcWidthSizeExp
			nullptr, 0,								// pcHeightSizeExp
			*/
		},
	};

#undef MX_FPS_W
#undef MX_FPS_H

	// == Functions.
	// Creates the window.
	CWidget * CFloatingPointStudioLayout::CreateFloatingPointStudioWindow( CWidget * _pwParent ) {
		std::vector<LSW_WIDGET_LAYOUT> vLayouts;
		std::vector<CSecureString> sStrings;
		std::vector<CSecureWString> sStringsW;
		CLayoutManager::UnencryptLayouts( m_wlMainWindow, MX_ELEMENTS( m_wlMainWindow ),
			vLayouts,
			sStringsW,
			sStrings );

		mx::CLayoutManager * plmLayout = static_cast<mx::CLayoutManager *>(lsw::CBase::LayoutManager());
		CFloatingPointStudioWindow::PrepareFloatingPointStudio();
		CWidget * pwThis = plmLayout->CreateWindowX( &vLayouts[0], MX_ELEMENTS( m_wlMainWindow ),
			nullptr, 0,
			_pwParent );
		CLayoutManager::CleanEncryptedStrings( sStringsW, sStrings );

		return pwThis;
	}

}	// namespace mx
