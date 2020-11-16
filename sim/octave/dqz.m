clear all
close all
##theta = 60; % [deg] angle of rotor

% DQZ Transform combines clarke and park transforms: transforms from 3-phase to
% alpha, beta, gamma, then from alpha, beta, gamma to rotor reference frame

% Direct Quadrature Zero Transformation
% Transforms phase a, b, c currents in the XYZ reference frame into
% direct, quadrature, zero currents in the rotating rotor reference frame
% [i_d; i_q; i_z] = T_dqz_fwd * [i_a; i_b; i_c]
function retval = T_dqz_fwd (theta)
  retval = sqrt(2/3) * ...
         [ cosd(theta)      cosd(theta - 120)   cosd(theta + 120); ...
           -sind(theta)     -sind(theta-120)    -sind(theta + 120); ...
           sqrt(2)/2        sqrt(2)/2           sqrt(2)/2];
end
              
% Direct Quadrature Zero Inverse Transformation
% Transforms direct, quadrature, zero currents into the phase a, b, c currents
% in the XYZ reference frame.
% [i_a; i_b; i_c] = T_dqz_rev * [i_d; i_q; i_z]
function retval = T_dqz_rev (theta)
  retval = sqrt(2/3) * ...
         [ cosd(theta)      -sind(theta)        sqrt(2)/2; ...
           cosd(theta-120)  -sind(theta-120)    sqrt(2)/2; ...
           cosd(theta+120)  -sind(theta+120)    sqrt(2)/2];
end

% Simulate a full rotation
i_d = 0; % direct component of stator current
i_q = 10; % quadrature component of stator current
i_z = 0; % zero component of stator current

NUM_STEPS = 1000;

i_abc = zeros(3, NUM_STEPS);
i_dqz = zeros(3, NUM_STEPS);

index = 1;
for theta=linspace(0, 360, NUM_STEPS)
  i_abc(:, index) = T_dqz_rev(theta) * [i_d; i_q; i_z];
  i_dqz(:, index) = T_dqz_fwd(theta) * i_abc(:, index); % cross check
  index = index + 1;
end

subplot(2, 1, 1)
plot(i_abc(1, :))
hold on
plot(i_abc(2, :))
plot(i_abc(3, :))
legend('i_a', 'i_b', 'i_c', 'location', 'northeast')
xlabel('Theta [deg]')
ylabel('Phase Current [A]')

subplot(2, 1, 2)
plot(i_dqz(1, :))
hold on
plot(i_dqz(2, :))
plot(i_dqz(3, :))
legend('i_d', 'i_q', 'i_z', 'location', 'northeast')
xlabel('Theta [deg]')
ylabel('Phase Current [A]')

##% this should not be [1; 2; 3]
##T_dqz_fwd(theta) * [1; 2; 3]
##% this should be [1; 2; 3]
##T_dqz_rev(theta) * T_dqz_fwd(theta) * [1; 2; 3]