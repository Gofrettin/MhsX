#pragma once
#include "../MXMhsX.h"
#include "../Options/MXOptions.h"
#include <Layout/LSWWidgetLayout.h>
#include <Widget/LSWWidget.h>

using namespace lsw;

namespace mx {
	
	class COptionsLayout {
	public :
		// == Enumerations.
		// Control ID's.
		enum MX_OPTIONS_IDS : WORD {
			MX_OI_NONE,
			MX_OI_DIALOG,
			MX_OI_LIST,
			MX_OI_OK,
			MX_OI_CANCEL,

			MX_OI_GENERAL,
			MX_OI_GENERAL_REFRESH_RATE,
			MX_OI_GENERAL_REFRESH_FOUND_ADDRESSES,
			MX_OI_GENERAL_REFRESH_FOUND_ADDRESSES_CB,
			MX_OI_GENERAL_TPS_0,

			MX_OI_GENERAL_REFRESH_MAIN_LIST,
			MX_OI_GENERAL_REFRESH_MAIN_LIST_CB,
			MX_OI_GENERAL_TPS_1,

			MX_OI_GENERAL_UPDDATE_LOCKED_VALUE,
			MX_OI_GENERAL_UPDDATE_LOCKED_VALUE_CB,
			MX_OI_GENERAL_TPS_2,

			MX_OI_GENERAL_UPDDATE_EXP_EVAL,
			MX_OI_GENERAL_UPDDATE_EXP_EVAL_CB,
			MX_OI_GENERAL_TPS_3,

			MX_OI_GENERAL_VIEW_SETTINGS,
			MX_OI_GENERAL_VIEW_CODE_NAMES,
			MX_OI_GENERAL_VIEW_SIZES,
			MX_OI_GENERAL_VIEW_RANGES,
			MX_OI_GENERAL_VIEW_EXAMPLE,

			MX_OI_GENERAL_FORMAT_SETTINGS,
			MX_OI_GENERAL_FORMAT_HEX,
			MX_OI_GENERAL_FORMAT_OCT,
			MX_OI_GENERAL_FORMAT_SHORT_ENUMS,

			MX_OI_GENERAL_SEARCH,
			MX_OI_GENERAL_SEARCH_SEARCH_RANGES,
			MX_OI_GENERAL_SEARCH_MEM_IMAGE,
			MX_OI_GENERAL_SEARCH_MEM_PRIVATE,
			MX_OI_GENERAL_SEARCH_MEM_MAPPED,
			MX_OI_GENERAL_SEARCH_ANYTHING,

			MX_OI_GENERAL_SEARCH_THREAD_PRIORITY,
			MX_OI_GENERAL_SEARCH_TP_NORMAL,
			MX_OI_GENERAL_SEARCH_TP_HIGH,
			MX_OI_GENERAL_SEARCH_TP_CRIT,

			MX_OI_GENERAL_SEARCH_BUFFER,
			MX_OI_GENERAL_SEARCH_BUFFER_SIZE,
			MX_OI_GENERAL_SEARCH_BUFFER_SIZE_EDIT,
			
			MX_OI_GENERAL_SEARCH_MISC,
			MX_OI_GENERAL_SEARCH_POSTFLUSH,
			MX_OI_GENERAL_SEARCH_PRECACHE,
			MX_OI_GENERAL_SEARCH_PAUSE,

			MX_OI_GENERAL_SEARCH_DOTS,

			MX_OI_GENERAL_SEARCH_USE_EPSILON,
			MX_OI_GENERAL_SEARCH_SMART_EPS,
			MX_OI_GENERAL_SEARCH_EPSILON,
			MX_OI_GENERAL_SEARCH_EPSILON_EDIT,

			MX_OI_SEARCH_EX,
			MX_OI_SEARCH_EX_BYTESWAP,
			MX_OI_SEARCH_EX_BYTESWAP_TYPE_LABEL,
			MX_OI_SEARCH_EX_BYTESWAP_TYPE_COMBO,

			MX_OI_OPEN_PROCESS,
			MX_OI_OPEN_PROCESS_SHOW_GROUP,
			MX_OI_OPEN_PROCESS_PROCESS,
			MX_OI_OPEN_PROCESS_PROCESSID,
			MX_OI_OPEN_PROCESS_PATH,
			MX_OI_OPEN_PROCESS_WINDOWS,
			MX_OI_OPEN_PROCESS_CHILDWINDOWS,
			MX_OI_OPEN_PROCESS_PARENT,
			MX_OI_OPEN_PROCESS_X86,
			MX_OI_OPEN_PROCESS_ALL,
			MX_OI_OPEN_PROCESS_NONE,
			MX_OI_OPEN_PROCESS_EXPLAIN,


			MX_OI_HOTKEYS,
			MX_OI_HOTKEYS_LIST,
			MX_OI_HOTKEYS_ADD,
			MX_OI_HOTKEYS_DELETE,
			MX_OI_HOTKEYS_UP,
			MX_OI_HOTKEYS_DOWN,
			MX_OI_HOTKEYS_OPTIONS_GROUP,
			MX_OI_HOTKEYS_OPTIONS_KEY_LABEL,
			MX_OI_HOTKEYS_OPTIONS_KEY_COMBO,
			MX_OI_HOTKEYS_OPTIONS_KEY_BUTTON,
			MX_OI_HOTKEYS_OPTIONS_MOD_LABEL,
			MX_OI_HOTKEYS_OPTIONS_MOD_COMBO,
			MX_OI_HOTKEYS_OPTIONS_FUNCTION_LABEL,
			MX_OI_HOTKEYS_OPTIONS_FUNCTION_COMBO,
			MX_OI_HOTKEYS_OPTIONS_METHOD_LABEL,
			MX_OI_HOTKEYS_OPTIONS_METHOD_COMBO,
			MX_OI_HOTKEYS_OPTIONS_PARM1_DESC_LABEL,
			MX_OI_HOTKEYS_OPTIONS_PARM2_DESC_LABEL,
			MX_OI_HOTKEYS_OPTIONS_PARM3_DESC_LABEL,
			MX_OI_HOTKEYS_OPTIONS_PARM1_LABEL,
			MX_OI_HOTKEYS_OPTIONS_PARM2_LABEL,
			MX_OI_HOTKEYS_OPTIONS_PARM3_LABEL,
			MX_OI_HOTKEYS_OPTIONS_PARM1_EDIT,
			MX_OI_HOTKEYS_OPTIONS_PARM2_EDIT,
			MX_OI_HOTKEYS_OPTIONS_PARM3_EDIT,
			MX_OI_HOTKEYS_OPTIONS_WARNING_LABEL,
		};


		// == Functions.
		// Creates the Options dialog.  Makes an in-memory copy of the LSW_WIDGET_LAYOUT's so it can decode strings etc.
		static BOOL								CreateOptionsDialog( CWidget * _pwParent, MX_OPTIONS * _poOptions, int32_t _i32Page );

		// Creates the general options page.
		static CWidget *						CreateGeneralPage( CWidget * _pwParent, MX_OPTIONS * _poOptions );

		// Creates the open-process options page.
		static CWidget *						CreateOpenProcPage( CWidget * _pwParent, MX_OPTIONS * _poOptions );

		// Creates the general search options page.
		static CWidget *						CreateGeneralSearchPage( CWidget * _pwParent, MX_OPTIONS * _poOptions );

		// Creates the extended search options page.
		static CWidget *						CreateSearchExPage( CWidget * _pwParent, MX_OPTIONS * _poOptions );

		// Creates the hotkeys options page.
		static CWidget *						CreateHotkeysPage( CWidget * _pwParent, MX_OPTIONS * _poOptions );


	protected :
		// == Members.
		// The layout for the Options dialog.
		static LSW_WIDGET_LAYOUT				m_wlOptionsDialog[];

		// General section.
		static LSW_WIDGET_LAYOUT				m_wlOptionsGeneral[];

		// General search section.
		static LSW_WIDGET_LAYOUT				m_wlOptionsGeneralSearch[];

		// Extended search section.
		static LSW_WIDGET_LAYOUT				m_wlOptionsSearchEx[];

		// Open-process section.
		static LSW_WIDGET_LAYOUT				m_wlOptionsOpenProc[];

		// Hotkeys section.
		static LSW_WIDGET_LAYOUT				m_wlOptionsHotkeys[];


		// == Functions.
		// Default window-creation.
		static CWidget *						CreatePage( CWidget * _pwParent, const LSW_WIDGET_LAYOUT * _pwlLayout, size_t _sTotal, MX_OPTIONS * _poOptions );

	};

}	// namespace mx
