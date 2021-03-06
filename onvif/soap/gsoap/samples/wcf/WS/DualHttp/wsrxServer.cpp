/* wsrxServer.cpp
   Generated by gSOAP 2.8.15 from ../../../../import/wsrm5.h

Copyright(C) 2000-2013, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#if defined(__BORLANDC__)
#pragma option push -w-8060
#pragma option push -w-8004
#endif
#include "wsrxH.h"

SOAP_SOURCE_STAMP("@(#) wsrxServer.cpp ver 2.8.15 2013-07-31 01:06:18 GMT")


extern "C" SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap *soap)
{
#ifndef WITH_FASTCGI
	unsigned int k = soap->max_keep_alive;
#endif
	do
	{
#ifndef WITH_FASTCGI
		if (soap->max_keep_alive > 0 && !--k)
			soap->keep_alive = 0;
#endif
		if (soap_begin_serve(soap))
		{	if (soap->error >= SOAP_STOP)
				continue;
			return soap->error;
		}
		if (soap_serve_request(soap) || (soap->fserveloop && soap->fserveloop(soap)))
		{
#ifdef WITH_FASTCGI
			soap_send_fault(soap);
#else
			return soap_send_fault(soap);
#endif
		}

#ifdef WITH_FASTCGI
		soap_destroy(soap);
		soap_end(soap);
	} while (1);
#else
	} while (soap->keep_alive);
#endif
	return SOAP_OK;
}

#ifndef WITH_NOSERVEREQUEST
extern "C" SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap *soap)
{
	soap_peek_element(soap);
	if ((soap->action && !strcmp(soap->action, "http://www.w3.org/2005/08/addressing/soap/fault")))
		return soap_serve_SOAP_ENV__Fault(soap);
	if ((soap->action && !strcmp(soap->action, "http://schemas.xmlsoap.org/ws/2005/02/rm/CreateSequence")))
		return soap_serve___wsrm__CreateSequence(soap);
	if ((soap->action && !strcmp(soap->action, "http://schemas.xmlsoap.org/ws/2005/02/rm/CloseSequence")))
		return soap_serve___wsrm__CloseSequence(soap);
	if ((soap->action && !strcmp(soap->action, "http://schemas.xmlsoap.org/ws/2005/02/rm/TerminateSequence")))
		return soap_serve___wsrm__TerminateSequence(soap);
	if ((soap->action && !strcmp(soap->action, "http://schemas.xmlsoap.org/ws/2005/02/rm/CreateSequenceResponse")))
		return soap_serve___wsrm__CreateSequenceResponse(soap);
	if ((soap->action && !strcmp(soap->action, "http://schemas.xmlsoap.org/ws/2005/02/rm/CloseSequenceResponse")))
		return soap_serve___wsrm__CloseSequenceResponse(soap);
	if ((soap->action && !strcmp(soap->action, "http://schemas.xmlsoap.org/ws/2005/02/rm/TerminateSequenceResponse")))
		return soap_serve___wsrm__TerminateSequenceResponse(soap);
	if ((soap->action && !strcmp(soap->action, "http://schemas.xmlsoap.org/ws/2005/02/rm/SequenceAcknowledgement")))
		return soap_serve___wsrm__SequenceAcknowledgement(soap);
	if ((soap->action && !strcmp(soap->action, "http://schemas.xmlsoap.org/ws/2005/02/rm/AckRequested")))
		return soap_serve___wsrm__AckRequested(soap);
	if ((soap->action && !strcmp(soap->action, "http://schemas.xmlsoap.org/ws/2005/02/rm/LastMessage")))
		return soap_serve___wsrm__LastMessage(soap);
	if ((soap->action && !strcmp(soap->action, "http://schemas.xmlsoap.org/ws/2005/02/rm/LastMessage")))
		return soap_serve___wsrm__LastMessage(soap);
	return soap->error = SOAP_NO_METHOD;
}
#endif

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_SOAP_ENV__Fault(struct soap *soap)
{	struct SOAP_ENV__Fault soap_tmp_SOAP_ENV__Fault;
	soap_default_SOAP_ENV__Fault(soap, &soap_tmp_SOAP_ENV__Fault);
	soap->encodingStyle = NULL;
	if (!soap_get_SOAP_ENV__Fault(soap, &soap_tmp_SOAP_ENV__Fault, "SOAP-ENV:Fault", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = SOAP_ENV__Fault(soap, soap_tmp_SOAP_ENV__Fault.faultcode, soap_tmp_SOAP_ENV__Fault.faultstring, soap_tmp_SOAP_ENV__Fault.faultactor, soap_tmp_SOAP_ENV__Fault.detail, soap_tmp_SOAP_ENV__Fault.SOAP_ENV__Code, soap_tmp_SOAP_ENV__Fault.SOAP_ENV__Reason, soap_tmp_SOAP_ENV__Fault.SOAP_ENV__Node, soap_tmp_SOAP_ENV__Fault.SOAP_ENV__Role, soap_tmp_SOAP_ENV__Fault.SOAP_ENV__Detail);
	if (soap->error)
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___wsrm__CreateSequence(struct soap *soap)
{	struct __wsrm__CreateSequence soap_tmp___wsrm__CreateSequence;
	struct wsrm__CreateSequenceResponseType wsrm__CreateSequenceResponse;
	soap_default_wsrm__CreateSequenceResponseType(soap, &wsrm__CreateSequenceResponse);
	soap_default___wsrm__CreateSequence(soap, &soap_tmp___wsrm__CreateSequence);
	soap->encodingStyle = NULL;
	if (!soap_get___wsrm__CreateSequence(soap, &soap_tmp___wsrm__CreateSequence, "-wsrm:CreateSequence", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __wsrm__CreateSequence(soap, soap_tmp___wsrm__CreateSequence.wsrm__CreateSequence, &wsrm__CreateSequenceResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_wsrm__CreateSequenceResponseType(soap, &wsrm__CreateSequenceResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_wsrm__CreateSequenceResponseType(soap, &wsrm__CreateSequenceResponse, "wsrm:CreateSequenceResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_wsrm__CreateSequenceResponseType(soap, &wsrm__CreateSequenceResponse, "wsrm:CreateSequenceResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___wsrm__CloseSequence(struct soap *soap)
{	struct __wsrm__CloseSequence soap_tmp___wsrm__CloseSequence;
	struct wsrm__CloseSequenceResponseType wsrm__CloseSequenceResponse;
	soap_default_wsrm__CloseSequenceResponseType(soap, &wsrm__CloseSequenceResponse);
	soap_default___wsrm__CloseSequence(soap, &soap_tmp___wsrm__CloseSequence);
	soap->encodingStyle = NULL;
	if (!soap_get___wsrm__CloseSequence(soap, &soap_tmp___wsrm__CloseSequence, "-wsrm:CloseSequence", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __wsrm__CloseSequence(soap, soap_tmp___wsrm__CloseSequence.wsrm__CloseSequence, &wsrm__CloseSequenceResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_wsrm__CloseSequenceResponseType(soap, &wsrm__CloseSequenceResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_wsrm__CloseSequenceResponseType(soap, &wsrm__CloseSequenceResponse, "wsrm:CloseSequenceResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_wsrm__CloseSequenceResponseType(soap, &wsrm__CloseSequenceResponse, "wsrm:CloseSequenceResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___wsrm__TerminateSequence(struct soap *soap)
{	struct __wsrm__TerminateSequence soap_tmp___wsrm__TerminateSequence;
	struct wsrm__TerminateSequenceResponseType wsrm__TerminateSequence_;
	soap_default_wsrm__TerminateSequenceResponseType(soap, &wsrm__TerminateSequence_);
	soap_default___wsrm__TerminateSequence(soap, &soap_tmp___wsrm__TerminateSequence);
	soap->encodingStyle = NULL;
	if (!soap_get___wsrm__TerminateSequence(soap, &soap_tmp___wsrm__TerminateSequence, "-wsrm:TerminateSequence", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __wsrm__TerminateSequence(soap, soap_tmp___wsrm__TerminateSequence.wsrm__TerminateSequence, &wsrm__TerminateSequence_);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_wsrm__TerminateSequenceResponseType(soap, &wsrm__TerminateSequence_);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_wsrm__TerminateSequenceResponseType(soap, &wsrm__TerminateSequence_, "wsrm:TerminateSequence", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_wsrm__TerminateSequenceResponseType(soap, &wsrm__TerminateSequence_, "wsrm:TerminateSequence", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___wsrm__CreateSequenceResponse(struct soap *soap)
{	struct __wsrm__CreateSequenceResponse soap_tmp___wsrm__CreateSequenceResponse;
	soap_default___wsrm__CreateSequenceResponse(soap, &soap_tmp___wsrm__CreateSequenceResponse);
	soap->encodingStyle = NULL;
	if (!soap_get___wsrm__CreateSequenceResponse(soap, &soap_tmp___wsrm__CreateSequenceResponse, "-wsrm:CreateSequenceResponse", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __wsrm__CreateSequenceResponse(soap, soap_tmp___wsrm__CreateSequenceResponse.wsrm__CreateSequenceResponse);
	if (soap->error)
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___wsrm__CloseSequenceResponse(struct soap *soap)
{	struct __wsrm__CloseSequenceResponse soap_tmp___wsrm__CloseSequenceResponse;
	soap_default___wsrm__CloseSequenceResponse(soap, &soap_tmp___wsrm__CloseSequenceResponse);
	soap->encodingStyle = NULL;
	if (!soap_get___wsrm__CloseSequenceResponse(soap, &soap_tmp___wsrm__CloseSequenceResponse, "-wsrm:CloseSequenceResponse", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __wsrm__CloseSequenceResponse(soap, soap_tmp___wsrm__CloseSequenceResponse.wsrm__CloseSequenceResponse);
	if (soap->error)
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___wsrm__TerminateSequenceResponse(struct soap *soap)
{	struct __wsrm__TerminateSequenceResponse soap_tmp___wsrm__TerminateSequenceResponse;
	soap_default___wsrm__TerminateSequenceResponse(soap, &soap_tmp___wsrm__TerminateSequenceResponse);
	soap->encodingStyle = NULL;
	if (!soap_get___wsrm__TerminateSequenceResponse(soap, &soap_tmp___wsrm__TerminateSequenceResponse, "-wsrm:TerminateSequenceResponse", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __wsrm__TerminateSequenceResponse(soap, soap_tmp___wsrm__TerminateSequenceResponse.wsrm__TerminateSequenceResponse);
	if (soap->error)
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___wsrm__SequenceAcknowledgement(struct soap *soap)
{	struct __wsrm__SequenceAcknowledgement soap_tmp___wsrm__SequenceAcknowledgement;
	soap_default___wsrm__SequenceAcknowledgement(soap, &soap_tmp___wsrm__SequenceAcknowledgement);
	soap->encodingStyle = NULL;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __wsrm__SequenceAcknowledgement(soap);
	if (soap->error)
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___wsrm__AckRequested(struct soap *soap)
{	struct __wsrm__AckRequested soap_tmp___wsrm__AckRequested;
	soap_default___wsrm__AckRequested(soap, &soap_tmp___wsrm__AckRequested);
	soap->encodingStyle = NULL;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __wsrm__AckRequested(soap);
	if (soap->error)
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___wsrm__LastMessage(struct soap *soap)
{	struct __wsrm__LastMessage soap_tmp___wsrm__LastMessage;
	soap_default___wsrm__LastMessage(soap, &soap_tmp___wsrm__LastMessage);
	soap->encodingStyle = NULL;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __wsrm__LastMessage(soap);
	if (soap->error)
		return soap->error;
	return soap_closesock(soap);
}

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of wsrxServer.cpp */
