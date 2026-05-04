#include <iostream>
#include <vector>
#include <iomanip> // 출력 간격을 맞추기 위해 사용

// 0-1 배낭 문제 함수
int knapsackDP(int W, const std::vector<int>& w_arr, const std::vector<int>& b_arr, int n) {
    // B 테이블 생성 및 0으로 초기화 (크기: [n+1][W+1])
    std::vector<std::vector<int>> B(n + 1, std::vector<int>(W + 1, 0));

    // 1~2. for w = 0 to W: B[0,w] = 0 (0번째 행 0으로 초기화)
    for (int w = 0; w <= W; ++w) {
        B[0][w] = 0;
    }

    // 3. for i = 1 to n
    for (int i = 1; i <= n; ++i) {
        // 4. B[i,0] = 0 (0번째 열 0으로 초기화)
        B[i][0] = 0;
        
        // 5. for w = 1 to W
        for (int w = 1; w <= W; ++w) {
            
            // 6. if wi <= w (아이템을 넣을 수 있는 경우)
            if (w_arr[i] <= w) {
                // 7. 넣는 것과 안 넣는 것 중 어느 것이 이득인지 비교
                if (b_arr[i] + B[i - 1][w - w_arr[i]] > B[i - 1][w]) {
                    // 8. 넣는 게 이득이면 값 갱신
                    B[i][w] = b_arr[i] + B[i - 1][w - w_arr[i]];
                } else {
                    // 9. 안 넣는 게 이득이면 이전 값 유지
                    B[i][w] = B[i - 1][w];
                }
            } 
            // 10. else (아이템이 너무 무거워서 못 넣는 경우)
            else {
                B[i][w] = B[i - 1][w]; // 이전 값 유지
            }
        }
    }

    // --- (보너스) DP 테이블 결과 출력 ---
    std::cout << "--- DP Table (B) ---\n";
    std::cout << "i \\ w|";
    for (int w = 0; w <= W; ++w) std::cout << std::setw(3) << w;
    std::cout << "\n---------------------\n";
    
    for (int i = 0; i <= n; ++i) {
        std::cout << "  " << i << "  |";
        for (int w = 0; w <= W; ++w) {
            std::cout << std::setw(3) << B[i][w];
        }
        std::cout << "\n";
    }
    std::cout << "---------------------\n";

    // 9. 최종 최적값 반환
    return B[n][W];
}

int main() {
    // 예제 데이터 설정
    int n = 4; // 아이템의 개수
    int W = 5; // 배낭의 최대 무게

    // 인덱스를 1부터 사용하기 위해 0번째 자리에 의미 없는 값(0)을 넣어줍니다.
    // 배열 인덱스와 수도코드의 i를 똑같이 맞추기 위함입니다.
    std::vector<int> weights = {0, 2, 3, 4, 5}; 
    std::vector<int> benefits = {0, 3, 4, 5, 6};

    std::cout << "[입력 정보]\n";
    std::cout << "배낭 최대 용량(W): " << W << "\n";
    for(int i=1; i<=n; ++i) {
        std::cout << "아이템 " << i << " - 무게: " << weights[i] << ", 가치: " << benefits[i] << "\n";
    }
    std::cout << "\n";

    // 함수 실행
    int maxBenefit = knapsackDP(W, weights, benefits, n);

    std::cout << "\n[결과]\n";
    std::cout << "배낭에 담을 수 있는 최대 가치는: " << maxBenefit << " 입니다.\n";

    return 0;
}