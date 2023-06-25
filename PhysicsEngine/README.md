Physics Engine in Nutshell
==========================


## What is Physics Engine?
- 물리 엔진은 컴퓨터 그래픽, 비디오 게임 및 영화 (CGI) 영역에서 사용되는 물리적 시스템의 대략적인 시뮬레이션을 제공하는 컴퓨터 소프트웨어이다.
- 강체 역학 (충돌 감지 포함), 연체 역학 및 유체 역학


## Types of Physics Engine
Real-time | High-precision
:---:|:---:
저성능 | 고성능
실시간 | 정밀
비디오게임, 인터렉티브 컴퓨팅 | 과학 시뮬레이션, 애니메이션


## Descriptions
### Scientific engines
- 

### Game engines
- 성능이 정확도보다 중시되기 때문에 Real-time 물리 엔진을 사용하나, 정확한 물리적 측정이 필요한 경우에는 근사치로 실제 물리학을 따른다.
- 지각적으로 정확한 근사치를 제공하는 데 초점을 둔다.
	- Semi-implicit euler method: 상용 미분 방정식을 수치적으로 해결하기 위한 방법 중 하나, 해석적으로 어려운 문제에 대해 근사적인 해를 얻을 수 있다.
- 동작 방식
	1. 초기 조건 설정: 변수들의 초깃값 설정
	2. 시간 단계 설정: △t 결정
	3. 시간에 따른 반복: 초기 단계 → 초기 단계 + △t
	4. 변수 암시적으로 업데이트: iterative solver (ex. Newthon's method)
	5. 변수 명시적으로 업데이트: 암시적인 변수를 얻은 후, 이전 시간 단계의 값 + 암시적 변수
	6. 종료 시간에 도달할 때까지 4. 5. 반복

### Collision detection(충돌 감지)
- Mesh: 복잡하고 상세한 모양 (꽃병, 나뭇가지 등)
- Shape: 간단한 모양 (실린더, 구, 정육면체 등)
- Collision Geometry: processing을 위해 복잡한 mesh대신 단순한 형태의 mesh를 사용하는 것
	- Minimum bounding box: 최소 둘레 경계 상자, 3차원에서는 직육면체, 2차원에서는 직사각형
![Minimum.Bounding.Box](https://en.wikipedia.org/wiki/Minimum_bounding_box#/media/File:Minimum_bounding_rectangle.svg)
	- Sphere: 구
	- Convex hull: 볼록한 선체
![Convex.Hull](https://en.wikipedia.org/wiki/Convex_hull#/media/File:ConvexHull.svg)

### Soft-body dynamics
- 

### Brownian motion(브라운 운동)
- 

###Paradims
- 


## References
- Wikipedia: <https://en.wikipedia.org/wiki/Physics_engine>
