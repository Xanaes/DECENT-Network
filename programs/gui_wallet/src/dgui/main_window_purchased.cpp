//main_window_purchased
// main_window_purchased
/*
 *	File: main_window_purchased.cpp
 *
 *	Created on: 20 Feb 2017
 *	Created by:
 *
 *  This file implements ...
 *
 */

#include "gui_wallet_mainwindow.hpp"
#include "decent_wallet_ui_gui_jsonparserqt.hpp"

void ParseDigitalContentFromVariant(decent::wallet::ui::gui::SDigitalContent* a_pContent,
                                    const fc::variant& a_result);

void gui_wallet::Mainwindow_gui_wallet::ManagementPurchasedGUI()
{
    int nIndex = m_pCentralWidget->usersCombo()->currentIndex();
    if((nIndex<0)||(nIndex>=m_user_ids.size())){return;}

    std::string sNewTask = "get_buying_history_objects_by_consumer " + m_user_ids[nIndex];
    SetNewTask3(sNewTask,this,NULL,&gui_wallet::Mainwindow_gui_wallet::TaskDonePurchasedGUI3);
    //SetNewTask(sNewTask,this,NULL,&gui_wallet::Mainwindow_gui_wallet::TaskDonePurchasedGUI);
}


void gui_wallet::Mainwindow_gui_wallet::TaskDonePurchasedGUI(void* a_clbkArg,int64_t a_err,
                                                             const std::string& a_task,const std::string& a_result)
{
    if(a_err)
    {
        //
    }
    else if(strstr(a_task.c_str(),"list_content_by_bought "))
    {
        __DEBUG_APP2__(0, "this code never can be caalled!!!!!!!!!!!!!!!!!!!!!!");
#if 0
        //QTableWidget& cContents = m_pCentralWidget->getDigitalContentsTable();
        std::string csGetContStr;
        m_vcDigContent.clear();
        GetDigitalContentsFromString(DCT::BOUGHT,m_vcDigContent,a_result.c_str());
        const int cnContsNumber(m_vcDigContent.size());

        for(int i(0); i<cnContsNumber; ++i)
        {
            csGetContStr = std::string("get_content \"") + m_vcDigContent[i].URI + "\"";
            SetNewTask(csGetContStr,this,(void*)((size_t)i),&Mainwindow_gui_wallet::TaskDoneFuncGUI);
        }
#endif

    }
    else if(strstr(a_task.c_str(),"get_content "))
    {
        __DEBUG_APP2__(0, "this code never can be caalled!!!!!!!!!!!!!!!!!!!!!!");
#if 0
        const int cnIndex (  (int)(  (size_t)a_clbkArg  )     );
        const int cnContsNumber(m_vcDigContent.size());
        if(cnIndex>=cnContsNumber){return;}
        ParseDigitalContentFromGetContentString(&m_vcDigContent[cnIndex],a_result);
        if(cnIndex==(cnContsNumber-1)){m_pCentralWidget->m_Purchased_tab.SetDigitalContentsGUI(m_vcDigContent);}
#endif
    }
    else if(strstr(a_task.c_str(),"get_buying_history_objects_by_consumer "))
    {
        __DEBUG_APP2__(0, "this code never can be caalled!!!!!!!!!!!!!!!!!!!!!!");
#if 0
        std::string csGetContStr;
        m_vcDigContent.clear();
        GetDigitalContentsFromString(DCT::GENERAL, m_vcDigContent,a_result.c_str());
        const int cnContsNumber(m_vcDigContent.size());

        for(int i(0); i<cnContsNumber; ++i)
        {
            csGetContStr = std::string("get_content \"") + m_vcDigContent[i].URI + "\"";
            SetNewTask(csGetContStr,this,(void*)((size_t)i),&Mainwindow_gui_wallet::TaskDoneFuncGUI);
        }
#endif
    }
}


void gui_wallet::Mainwindow_gui_wallet::TaskDonePurchasedGUI3(void* a_clbkArg,int64_t a_err,
                                                              const std::string& a_task,const fc::variant& a_result)
{
    __DEBUG_APP2__(1," ");

    if(a_err)
    {
        //
    }
    else if(strstr(a_task.c_str(),"list_content_by_bought "))
    {
    }
    else if(strstr(a_task.c_str(),"get_content "))
    {
        const int cnIndex (  (int)(  (size_t)a_clbkArg  )     );
        const int cnContsNumber(m_vcDigContent.size());
        if(cnIndex>=cnContsNumber){return;}
        ParseDigitalContentFromVariant(&m_vcDigContent[cnIndex],a_result);
        if(cnIndex==(cnContsNumber-1)){m_pCentralWidget->m_Purchased_tab.SetDigitalContentsGUI(m_vcDigContent);}
    }
    else if(strstr(a_task.c_str(),"get_buying_history_objects_by_consumer "))
    {
        std::string csGetContStr;
        m_vcDigContent.clear();
        GetDigitalContentsFromVariant(DCT::GENERAL, m_vcDigContent,a_result);
        const int cnContsNumber(m_vcDigContent.size());

        for(int i(0); i<cnContsNumber; ++i)
        {
            csGetContStr = std::string("get_content \"") + m_vcDigContent[i].URI + "\"";
            SetNewTask(csGetContStr,this,(void*)((size_t)i),&Mainwindow_gui_wallet::TaskDoneFuncGUI);
        }
    }
}
