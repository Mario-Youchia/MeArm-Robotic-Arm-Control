clc
clear
close all

% Servo-angle ranges used by the selected Arduino implementation.
theta_b = 0:180;   % Base servo
u_e = 0:135;       % Elbow servo
l_s = 25:180;      % Shoulder servo

% Servo offsets used by the selected inverse-kinematics implementation.
ElbowOffset = 89;
ShoulderOffset = 95;

% Convert servo angles to the corresponding kinematic joint angles.
theta = theta_b - 90;
l = l_s - ShoulderOffset;
u = 90 - (ElbowOffset - u_e);

% Calculate radial distance and height for all elbow/shoulder combinations.
numberOfJointCombinations = length(l) * length(u);

r = zeros(1, numberOfJointCombinations);
Z = zeros(1, numberOfJointCombinations);

k = 1;

for i = 1:length(l)
    for j = 1:length(u)
        r(k) = 65 ...
             + 80 * sind(l(i)) ...
             + 80 * sind(u(j));

        Z(k) = 57.3 ...
             + 80 * cosd(l(i)) ...
             - 80 * cosd(u(j));

        k = k + 1;
    end
end

% Rotate each radial workspace point through the base-servo range.
numberOfWorkspacePoints = length(theta) * length(r);

x = zeros(1, numberOfWorkspacePoints);
y = zeros(1, numberOfWorkspacePoints);
z = zeros(1, numberOfWorkspacePoints);

k = 1;

for i = 1:length(theta)
    for j = 1:length(r)
        x(k) = r(j) * cosd(theta(i));
        y(k) = r(j) * sind(theta(i));
        z(k) = Z(j);

        k = k + 1;
    end
end

scatter3(x, y, z, 4, '.');

xlabel('X position (mm)');
ylabel('Y position (mm)');
zlabel('Z position (mm)');
title('Robotic Arm Forward-Kinematics Workspace');

axis equal;
grid on;