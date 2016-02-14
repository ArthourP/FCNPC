/* =========================================
			
		FCNPC - Fully Controllable NPC
			----------------------

	- File: Player.h
	- Author(s): OrMisicL

  =========================================*/


#ifndef PLAYER_H
#define PLAYER_H

#include "CVector.h"
#include "Structs.h"
#include "Playback.h"
#include "Node.h"
#include <stdio.h>

class CPlayback;
struct CSyncData;
struct CVehicleSyncData;
struct CPlayer;

class CPlayerData
{
	public:
		CPlayerData(WORD playerId, char *szName);
		~CPlayerData();

		int GetId();

		void Destroy();
		bool Setup();
		void Process();
		bool Spawn(int iSkinId);
		bool Respawn();
		void Kill(int iKillerId, int iWeapon);
		void Update(int iState);
		void UpdateSync(int iState);
		void UpdateAim();
		bool IsSpawned();
		void SetSpawnPosition(CVector vecPosition);

		void SetOnFootSync(CSyncData *syncData);
		void SetVehicleSync(CVehicleSyncData *syncData);

		void SetName(char *szName);
		void GetName(char *szName, size_t size);

		bool SetState(BYTE byteState);
		BYTE GetState();

		void SetPosition(CVector vecPosition);
		void GetPosition(CVector *pvecPosition);
		void SetQuaternion(float *fQuaternion);
		void GetQuaternion(float *fQuaternion);
		void SetAngle(float fAngle);
		float GetAngle();
		void SetVelocity(CVector vecVelocity);
		void GetVelocity(CVector *pvecVelocity);

		void SetHealth(float fHealth);
		float GetHealth();
		void SetArmour(float fArmour);
		float GetArmour();

		void SetWeapon(BYTE byteWeaponId);
		BYTE GetWeapon();
		void SetAmmo(WORD wAmmo);
		WORD GetAmmo();

		void SetSkin(int iSkin);
		int GetSkin();
		void SetInterior(int iInterior);
		int GetInterior();

		void SetKeys(WORD wUDAnalog, WORD wLRAnalog, DWORD dwKeys);
		void GetKeys(WORD *pwUDAnalog, WORD *pwLRAnalog, DWORD *pdwKeys);

		void SetSpecialAction(int iActionId);
		int GetSpecialAction();

		bool GoTo(CVector vecPoint, int iType, bool bUseZMap, float fRadius = 0.0f);
		void StopMoving();
		bool IsMoving();

		void ToggleReloading(bool bToggle);
		void ToggleInfiniteAmmo(bool bToggle);

		void AimAt(CVector vecPoint, bool bShoot);
		void AimAtPlayer(WORD wHitId, bool bShoot);
		void StopAim();
		void MeleeAttack(DWORD dwTime);
		void StopAttack();
		bool IsAiming();
		bool IsShooting();
		bool IsReloading();


		void ProcessDamage(int iDamagerId, float fHealthLoss, int iWeaponId, int iBodypart);
		
		bool EnterVehicle(int iVehicleId, int iSeatId, int iType);
		bool ExitVehicle();
		bool PutInVehicle(int iVehicleId, int iSeatId);
		bool RemoveFromVehicle();
		bool IsInVehicle();
		int GetVehicleId();
		int GetSeatId();

		bool StartPlayingPlayback(char *szFile);
		void StopPlayingPlayback();
		void PausePlayingPlayback();
		void ResumePlayingPlayback();

		bool PlayNode(int iNodeId, int iType);
		void StopPlayingNode();
		int ChangeNode(int iNodeId, unsigned short usLinkId);

	private:
		WORD m_playerId;
		bool m_bSetup;
		char m_szName[MAX_PLAYER_NAME];
		bool m_bSpawned;
		bool m_bMoving;
		bool m_bUseZMap;
		bool m_bAiming;
		bool m_bReloading;
		bool m_bEntering;
		bool m_bJacking;
		bool m_bExiting;
		bool m_bPlaying;
		bool m_bPlayingNode;
		bool m_bMeleeAttack;
		float m_fLastDistance;
		DWORD m_dwUpdateTick;
		DWORD m_dwMoveTickCount;
		DWORD m_dwReloadTickCount;
		DWORD m_dwShootTickCount;
		DWORD m_dwEnterExitTickCount;
		DWORD m_dwMoveStartTime;
		DWORD m_dwMoveTime;
		DWORD m_dwMeleeDelay;
		CVector m_vecDestination;
		BYTE m_byteWeaponId;
		WORD m_wAmmo;
		WORD m_wHitId;
		BYTE m_byteHitType;
		WORD m_wVehicleToEnter;
		BYTE m_byteSeatToEnter;
		int m_iLastDamager;
		int m_iNodePoint;
		int m_iNodeLastPoint;
		int m_iNodeType;
		bool m_bHasReload;
		bool m_bHasInfiniteAmmo;
		CVector m_vecNodeVelocity;
		CPlayback *m_pPlayback;
		CNode *m_pNode;
		CVector m_vecAimAt;
		CPlayer *m_pPlayer;

};

#endif
