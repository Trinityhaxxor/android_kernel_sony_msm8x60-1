/*
 * Copyright (c) 2012, Code Aurora Forum. All rights reserved.
 *
 * Previously licensed under the ISC license by Qualcomm Atheros, Inc.
 *
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/*
 *
 * Airgo Networks, Inc proprietary. All rights reserved.
 * limSendMessages.h: Provides functions to send messages or Indications to HAL.
 * Author:    Sunit Bhatia
 * Date:       09/21/2006
 * History:-
 * Date        Modified by            Modification Information
 *
 * --------------------------------------------------------------------------
 *
 */
#ifndef __LIM_SEND_MESSAGES_H
#define __LIM_SEND_MESSAGES_H



#include "aniGlobal.h"
#include "limTypes.h"
#include "halMsgApi.h"
#include "sirParams.h"    

tSirRetStatus limSendCFParams(tpAniSirGlobal pMac, tANI_U8 bssIdx, tANI_U8 cfpCount, tANI_U8 cfpPeriod);
tSirRetStatus limSendBeaconParams(tpAniSirGlobal pMac, 
                                  tpUpdateBeaconParams pUpdatedBcnParams,
                                  tpPESession  psessionEntry );

//tSirRetStatus limSendBeaconParams(tpAniSirGlobal pMac, tpUpdateBeaconParams pUpdatedBcnParams);
#if defined WLAN_FEATURE_VOWIFI  
tSirRetStatus limSendSwitchChnlParams(tpAniSirGlobal pMac, tANI_U8 chnlNumber, 
                                      tSirMacHTSecondaryChannelOffset secondaryChnlOffset, 
                                      tPowerdBm maxTxPower,tANI_U8 peSessionId);
#else
tSirRetStatus limSendSwitchChnlParams(tpAniSirGlobal pMac, tANI_U8 chnlNumber, 
                                      tSirMacHTSecondaryChannelOffset secondaryChnlOffset, 
                                      tANI_U8 localPwrConstraint,tANI_U8 peSessionId);
#endif
tSirRetStatus limSendEdcaParams(tpAniSirGlobal pMac, tSirMacEdcaParamRecord *pUpdatedEdcaParams, tANI_U16 bssIdx, tANI_BOOLEAN highPerformance);
tSirRetStatus limSetLinkState(tpAniSirGlobal pMac, tSirLinkState state,  tSirMacAddr bssId, 
                              tSirMacAddr selfMac, tpSetLinkStateCallback callback,
                              void *callbackArg);
#ifdef WLAN_FEATURE_VOWIFI_11R
extern tSirRetStatus limSetLinkStateFT(tpAniSirGlobal pMac, tSirLinkState 
state,tSirMacAddr bssId, tSirMacAddr selfMacAddr, int ft, tpPESession psessionEntry);
#endif
tSirRetStatus limSendSetTxPowerReq(tpAniSirGlobal pMac, tpSirSetTxPowerReq pTxPowerReq);
tSirRetStatus limSendGetTxPowerReq(tpAniSirGlobal pMac, tpSirGetTxPowerReq pTxPowerReq);

void limSetActiveEdcaParams(tpAniSirGlobal pMac, tSirMacEdcaParamRecord *plocalEdcaParams, tpPESession psessionEntry);

#define CAPABILITY_FILTER_MASK  0x73CF
#define ERP_FILTER_MASK         0xF8
#define EDCA_FILTER_MASK        0xF0
#define QOS_FILTER_MASK         0xF0
#define HT_BYTE0_FILTER_MASK    0x0
#define HT_BYTE2_FILTER_MASK    0xEB
#define HT_BYTE5_FILTER_MASK    0xFD
#define DS_PARAM_CHANNEL_MASK   0x0


tSirRetStatus limSendBeaconFilterInfo(tpAniSirGlobal pMac);


#endif