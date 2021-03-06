/*
 *  Author: bwilliams
 *  Created: April 6, 2012
 *
 *  Copyright (C) 2012-2016 VMware, Inc.  All rights reserved. -- VMware Confidential
 *
 *  This code was generated by the script "build/dev/codeGen/genCppXml". Please
 *  speak to Brian W. before modifying it by hand.
 *
 */

#include "stdafx.h"

#include "Doc/DocXml/MgmtTypesXml/MgmtBatchXml.h"

#include "Doc/DocXml/MultiPmeMgmtRequestXml/PmeIdCollectionXml.h"

#include "Doc/MgmtTypesDoc/CMgmtBatchDoc.h"
#include "Doc/MultiPmeMgmtRequestDoc/CMultiPmeMgmtBatchDoc.h"
#include "Doc/MultiPmeMgmtRequestDoc/CPmeIdCollectionDoc.h"
#include "Xml/XmlUtils/CXmlElement.h"
#include "Doc/DocXml/MultiPmeMgmtRequestXml/MultiPmeMgmtBatchXml.h"

using namespace Caf;

void MultiPmeMgmtBatchXml::add(
	const SmartPtrCMultiPmeMgmtBatchDoc multiPmeMgmtBatchDoc,
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("MultiPmeMgmtBatchXml", "add");

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(multiPmeMgmtBatchDoc);
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const SmartPtrCPmeIdCollectionDoc pmeIdCollectionVal =
			multiPmeMgmtBatchDoc->getPmeIdCollection();
		CAF_CM_VALIDATE_SMARTPTR(pmeIdCollectionVal);

		const SmartPtrCXmlElement pmeIdCollectionXml =
			thisXml->createAndAddElement("pmeIdCollection");
		PmeIdCollectionXml::add(pmeIdCollectionVal, pmeIdCollectionXml);

		const SmartPtrCMgmtBatchDoc batchVal =
			multiPmeMgmtBatchDoc->getBatch();
		CAF_CM_VALIDATE_SMARTPTR(batchVal);

		const SmartPtrCXmlElement batchXml =
			thisXml->createAndAddElement("batch");
		MgmtBatchXml::add(batchVal, batchXml);
	}
	CAF_CM_EXIT;
}

SmartPtrCMultiPmeMgmtBatchDoc MultiPmeMgmtBatchXml::parse(
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("MultiPmeMgmtBatchXml", "parse");

	SmartPtrCMultiPmeMgmtBatchDoc multiPmeMgmtBatchDoc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const SmartPtrCXmlElement pmeIdCollectionXml =
			thisXml->findRequiredChild("pmeIdCollection");

		SmartPtrCPmeIdCollectionDoc pmeIdCollectionVal;
		if (! pmeIdCollectionXml.IsNull()) {
			pmeIdCollectionVal = PmeIdCollectionXml::parse(pmeIdCollectionXml);
		}

		const SmartPtrCXmlElement batchXml =
			thisXml->findRequiredChild("batch");

		SmartPtrCMgmtBatchDoc batchVal;
		if (! batchXml.IsNull()) {
			batchVal = MgmtBatchXml::parse(batchXml);
		}

		multiPmeMgmtBatchDoc.CreateInstance();
		multiPmeMgmtBatchDoc->initialize(
			pmeIdCollectionVal,
			batchVal);
	}
	CAF_CM_EXIT;

	return multiPmeMgmtBatchDoc;
}

