% Clarke Transform: converts 3 phase currents into alpha, beta, gamma currents
% [i_alpha; i_beta; i_gamma] = T_fwd_clarke * [i_a, i_b, i_c]
% Note: for a 3-phase motor, i_a + i_b + i_c = 0 so i_gamma = 0
T_fwd_clarke = 2/3 * [ 1 -1/2 -1/2; 0 sqrt(3)/2 -sqrt(3)/2; 1/2 1/2 1/2];

% Inverse Clarke Transform
% [i_a; i_b; i_c] = T_rev_clarke * [i_alpha; i_beta; i_gamma]
T_rev_clarke = [1 0 1; -1/2 sqrt(3)/2 1; -1/2 -sqrt(3)/2 1];

% this should yield not [1; 2; 3]
T_fwd_clarke * [1; 2; 3]

% this should yield [1; 2; 3]
T_rev_clarke * T_fwd_clarke * [1; 2; 3]