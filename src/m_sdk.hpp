enum bone : int {
	Head = 110,
	Neck = 67,
	Chest = 66,
	Pelvis = 2,
	LShoulder = 9,
	LElbow = 10,
	LHand = 11,
	RShoulder = 38,
	RElbow = 39,
	RHand = 40,
	LHip = 71,
	LKnee = 72,
	LFoot = 73,
	RHip = 78,
	RKnee = 79,
	RFoot = 82,
	Root = 0
};

enum EFortWeaponType : int
{
	Rifle = 0,
	Shotgun = 1,
	Smg = 2,
	Sniper = 3
};

enum offset {
	Uworld = 0x126CF528,
	PrimaryPickupItemEntry = 0x350,
	levels = 0x178, // https://dumpspace.spuckwaffel.com/Games/?hash=6b77eceb&type=classes&idx=UWorld&member=Levels
	ItemDefinition = 0x18,
	OwningGameInstance = 0x1d8,
	displayname = 0x38,
	tier = 0x13B,
	last_sumbit = 0x2E8,
	last_render = 0x2F0,
	current_wepon = 0xa20,
	weapon_data = 0x4f0,
	btargetedbuild = 0x1710,
	game_state = 0x160,
	local_player = 0x38,
	player_controller = 0x30,
	acknowledged_pawn = 0x338,
	skeletal_mesh = 0x318,
	player_state = 0x2b0,
	root_component = 0x198,
	velocity = 0x168,
	relative_location = 0x120,
	relative_rotation = 0x138,
	team_index = 0x1251,
	player_array = 0x2A8,
	pawn_private = 0x308,
	component_to_world = 0x1c0,
	bone_array = 0x5B0,
	pname = 0xaf0,
};


namespace SDK {

	int UWorlds = 0x10C628D8;
	int Fname = 0x12144040;
	int Gameinstance = 0x1d8; // Class Engine.World -> struct UGameInstance

	int LocalPlayers = 0x38; // Class Engine.GameInstance -> struct TArray<struct ULocalPlayer*> LocalPlayers; 
	int PlayerController = 0x30; // Class Engine.Player - > struct APlayerController

	int LocalPawn = 0x338; // Class Engine.PlayerController - > struct APawn* AcknowledgedPawn 

	int PlayerState = 0x2b0; // Class Engine.Pawn - > struct APlayerState* PlayerState;
	int RootComponet = 0x198;  //Class Engine.Actor -> struct USceneComponent* RootComponent;
	int GameState = 0x160; // Class Engine.World -> struct AGameStateBase* GameState;
	int PersistentLevel = 0x30; // Class Engine.World -> struct ULevel* PersistentLevel;

	int Velocity = 0x168; // Class Engine.SceneComponent -> struct FVector ComponentVelocity;  
	int GunName = 0x98;
	int IsDBNO = 0x93a; //	FortniteGameClass.AFortPawn -> char bIsDBNO : 1 
	int IsDying = 0x758; //	FortniteGameClass.AFortPawn -> char bIsDying : 1 

	int Cameramanager = 0x348; // Class Engine.PlayerController -> struct APlayerCameraManager* PlayerCameraManager; 
	int Mesh = 0x318; // Class Engine.Character struct USkeletalMeshComponent* Mesh x318(0x08) 
	int Revivefromdbnotime = 0x4c78; // FortniteGameClass.AFortPlayerPawnAthena - > float ReviveFromDBNOTime; 
	int TeamId = 0x1251;  // FortniteGameClass.AFortPlayerStateAthena - > char TeamIndex;  
	int pawn_private = 0x308; // Class Engine.PlayerState -> struct APawn* PawnPrivate;  
	int bIsABot = 0x29a; // Class Engine.PlayerState -> char bIsABot : 1;  
	int RelativeLocation = 0x120; // Class Engine.SceneComponent -> struct FVector RelativeLocation;  
	int PlayerArray = 0x2a8; // Class Engine.GameStateBase -> struct TArray<struct APlayerState*> PlayerArray;  
	int DefaultFOV = 0x2a4; //Engine_classes.APlayerCameraManager - > DefaultFOV 
	int AActor = 0xA0;
	int ActorCount = 0xA8;
	int ComponetToWorld = 0x1c0;
	int BoneArray = 0x598;
	int LAST_SUMBIT_TIME = 0x2E8;
	int LAST_SUMBIT_TIME_ON_SCREEN = 0x2F0;
	int Levels = 0x170;

	namespace FortWeapon {

		int CurrentWeapons = 0xa20;// Class FortniteGame.FortPawn struct AFortWeapon* CurrentWeapon
		int WeaponData = 0x4f0; // Class FortniteGame.FortWeapon struct UFortWeaponItemDefinition* WeaponData
		int ItemName = 0x38; // Class ItemizationCoreRuntime.ItemDefinitionBase -> //struct FText ItemName;
		int Tier = 0x13b; // Class FortniteGame.FortItemDefinition - > enum class EFortItemTier Tier
		int bIsReloadingWeapon = 0x388; // Class FortniteGame.AFortWeapon -> bool bIsReloadingWeapon;
		int AmmoCount = 0xe54; // Class FortniteGame.AActor -> int32_t AmmoCount;
		int bIsTargeting = 0x581; // Class FortniteGame.CustomCharacterPartAnimInstance -> char bIsTargeting : 1;


	}
	namespace Character {
		int bIsCrouched = 0x45c; // Class Engine.Character -> char bIsCrouched : 1;
	}
	namespace FortPawn {

		int bIsJumping = 0xa18; //Class FortniteGame.AFortPawn - > char bIsJumping : 1; 
		int bIsSliding = 0x75b; //Class FortniteGame.AFortPawn - > char bIsSliding : 1;
		int TargetedFortPawn = 0x1890;  //Class FortniteGame.AFortPlayerController - > TargetedFortPawn
	}
}
