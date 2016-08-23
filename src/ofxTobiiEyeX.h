#ifndef __OFX_TOBII_EYEX__
#define __OFX_TOBII_EYEX__

#include "ofMain.h"
#include "EyeX.h"

namespace ofxTobiiEyeX
{
	class BaseTobiiEyeXApi
	{
	protected:
		TX_CONTEXTHANDLE hContext;
		TX_HANDLE hGlobalInteractorSnapshot;

	public:
		BaseTobiiEyeXApi();
		virtual ~BaseTobiiEyeXApi();

		virtual void update() = 0;
		virtual bool open() = 0;
		virtual bool close() = 0;
	};

	class GazePoint : public BaseTobiiEyeXApi
	{
	protected:
		TX_GAZEPOINTDATAEVENTPARAMS m_GazePointDataEventParams;

	public:
		GazePoint();
		virtual ~GazePoint();

		void update();
		bool open(TX_CONSTSTRING InstractorId, TX_GAZEPOINTDATAPARAMS params);
		bool open();
		bool close();

		inline const TX_GAZEPOINTDATAEVENTPARAMS& getGazePointParams() { return m_GazePointDataEventParams; }
		inline ofPoint getGazePoint() { return ofPoint(m_GazePointDataEventParams.X, m_GazePointDataEventParams.Y); }
	};

	class EyePosition : public BaseTobiiEyeXApi
	{
	protected:
		TX_EYEPOSITIONDATAEVENTPARAMS m_EyePositionDataEventParams;

	public:
		EyePosition();
		virtual ~EyePosition();

		void update();
		bool open(TX_CONSTSTRING InstractorId);
		bool open();
		bool close();

		inline TX_EYEPOSITIONDATAEVENTPARAMS& getEyePosition() { return m_EyePositionDataEventParams; }
	};
}

#endif
