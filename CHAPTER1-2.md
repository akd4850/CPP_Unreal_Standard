# Chapter 1
 - 언리얼 프로젝트 폴더 구성요소
	- Config : 게임 프로젝트의 설정 값을 보관
	- Content : 애셋 관리
	- Intermediate : 프로젝트 관리에 필요한 임시 파일 저장
	- Saved : 에디터 작업 중에 생성된 결과물을 저장
	- Binaries : C++ 코드가 컴파일된 결과물을 저장
	- Source
	- .sln
		- **Config, Content, Source** 는 삭제하면 안됨
		- 나머지 폴더는 언리얼 프로젝트가 재생성
		
	- .uproject
		{
			"FileVersion": 3,
			"EngineAssociation": "4.27",
			"Category": "",
			"Description": "",
			"Modules": [
				{
					"Name": "ArenaBattle_KMS",
					"Type": "Runtime",
					"LoadingPhase": "Default",
					"AdditionalDependencies": [
						"Engine"
					]
				}
			]
		}
		- ArenaBattle 이라는 C++ 모듈도 로딩하라는 명령
		- 언리얼은 Binaries 폴더에서 ArenaBattle 이라는 모듈을 찾음
		- 모듈 이름 규칙 UE4Editor-ArenaBattle.dll
			- 컴파일이 되면 생성
		- 언이렁 C++ 컴파일 과정
			- 소스코드 -> 컴파일 -> UE4Editor-ArenaBattle.dll -> 검색후 탑재 -> .uproject 에서 구동

# Chapter 2
 - 액터의 설계
	- 언리얼 구성요소
		- 월드
		- 액터(Actor) : 콘텐츠를 구성하는 최소 단위
		- 레벨(Level) : 월드에 배치된 액터들의 집합(스테이지)(
		- 컴포넌트(Component)
			- 액터의 주요 기능
				- 시각적, 물리적, 움직임
				- 이러한 규격화된 기능을 컴포넌트라고 함
			- 주요 컴포넌트
				- 스태틱메시 : 애니메이션이 없는 모델링 애셋. 주로 배경 등
				- 스켈레탈메시 : 애니메이션이 있는 모델링 애셋. 주로 캐릭터 등
				- 콜리전
				- 카메라
				- 오디오
				- 파티클
				- 라이트
				- 무브먼트 : 물체에 특정한 움직임을 부여
			- 액터는 여러 개의 컴포넌트를 가질 수 있으며, 그 중에서 **대표하는 하나의 컴포넌트를 반드시 지정해야 함**
				- 이를 **루트 컴포넌트(Root Component)**
	- UStaticMeshComponent* Body;
		- 원래 C++ 에서는 포인터를 선언하면 명시적으로 객체를 소멸시켜야함
		- 하지만 언리얼 엔진은 **Runtime을 통해 객체가 더 이상 사용되지 않으면 할당된 메모리를 자동으로 소멸**시키는 기능을 제공
		- 위 기능을 동작하게 만드려면 **UPROPERTY** 매크로 선언이 필요
		- 하지만 모든 객체에 사용은 안되고, **언리얼 오브젝트** 객체만 사용 가능
	- 언리얼 오브젝트 클래스 규칙
		- UCLASS() 및 내부에 GENERATED_BODY
		- A는 Actor 클래스, U는 Actor가 아닌 클래스
		- generated.h 헤더 파일 자동으로 생성되고 #include 로 반드시 포함
		- 외부 모듈 공개 모듈명_API
	- 액터와 에디터 연동
		- UPROPERTY(VisibleAnyWhere): 에디터 디테일에서 볼 수 있도록 선언
	- 애셋 지정
		- C++ 코드에서 애셋을 불러드리면
		- **애셋의 고유한 키 값을 파악하고 애셋을 관리하는 시스템에 키 값으로 질의를 던져 애셋의 포인트를 가져와야 한다**
		- 애셋 선택 후 복사하면 가져올 수 있다.
		- **{오브젝트 타입}'{폴더명}/{파일명}.{애셋명}'**